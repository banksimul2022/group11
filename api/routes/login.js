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
        response.send(false);
    }
    else {
        login.checkPincode(cardNumber, function (dbError, dbResult) {
            if (dbError) {
                response.json(dbError);
            }
            else {
                if (dbResult.length > 0) {
                    bcrypt.compare(pinCode,dbResult[0].pinKoodi, function (err, compareResult) {
                        if(compareResult) {
                            console.log("pincode correct!");
                            const token = generateAccessToken({ cardNumber: cardNumber });
                            response.json(token);
                        }
                        else {
                            console.log("wrong pincode");
                            response.send(false);
                        }
                    });
                }
                else {
                    console.log("card does not exist");
                    response.send(false);
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