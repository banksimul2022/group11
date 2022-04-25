const express = require('express');
const router = express.Router();
const login = require('../models/login_model');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
function(request, response) {
    const { cardNumber, pinCode} = request.body;

    // Cardnumber or pincode missing
    // Send error and stop process
    if(!cardNumber || !pinCode) {
        console.log("cardnumber or pincode missing");
        response.json({ error: "cardnumber or pincode missing"});
    }
    else {
        // Send pincode authorization query
        login.checkPincode(cardNumber, function (dbError, dbResult) {
            // Send database error as json
            if (dbError) {
                response.json({ error: dbError.sqlMessage });
            }
            // Query ok, continue checking
            else {
                // Crypted pincode and card locked -information send in result
                if (dbResult.length > 0) {
                    bcrypt.compare(pinCode,dbResult[0].pinKoodi, function (err, compareResult) {
                        // Check compare result and card is unlocked
                        if(compareResult && !dbResult[0].lukittu) {
                            console.log("pincode correct");
                            const token = generateAccessToken({ cardNumber: cardNumber });
                            response.json({ token: token,
                                            result: "Login succeeded" 
                                        });
                        }
                        // If card is locked send error
                        else if (dbResult[0].lukittu) {
                            console.log("card is locked");
                            response.json({ error: "card is locked"} )
                        }
                        // Wrong pincode, send error
                        else {
                            console.log("wrong pincode");
                            response.json({ error: "wrong pincode" });
                        }
                    });
                }
                // Result empty, card not found
                else {
                    console.log("card does not exist");
                    response.json({ error: "card does not exist" });
                }
            }
        });
    }
});

function generateAccessToken(cardNumber) {
    dotenv.config();
    return jwt.sign(cardNumber, process.env.MY_TOKEN, {expiresIn: '1800s' });
}

module.exports = router;