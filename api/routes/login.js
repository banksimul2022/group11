const express = require('express');
const router = express.Router();
const login = require('../models/login_model');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
function(request, response) {
    const { cardNumber, pinCode} = request.body;
    if(!cardNumber || !pinCode) {
        console.log("cardnumber or pincode missing");
        response.json({ error: "cardnumber or pincode missing"});
    }
    else {
        login.checkPincode(cardNumber, function (dbError, dbResult) {
            if (dbError) {
                response.json({ error: dbError.sqlMessage });
            }
            else {
                if (dbResult.length > 0) {
                    console.log(dbResult);
                    bcrypt.compare(pinCode,dbResult[0].pinKoodi, function (err, compareResult) {
                        if(compareResult && !dbResult[0].lukittu) {
                            console.log("pincode correct");
                            const token = generateAccessToken({ cardNumber: cardNumber });
                            response.json({ token: token,
                                            result: "Login succeeded" 
                                        });
                        }
                        else if (dbResult[0].lukittu) {
                            console.log("card is locked");
                            response.json({ error: "card is locked"} )
                        }
                        else {
                            console.log("wrong pincode");
                            response.json({ error: "wrong pincode" });
                        }
                    });
                }
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