const { response } = require('express')
const express = require('express')
const router = express.Router()
const operaatiot = require('../models/operaatiot_model')

router.post('/tilitapahtumat/', function(request, response) {
  const params = { cardNumber, offset = 0, noOfRows = 10 } = request.body;
  if(!cardNumber) {
      console.log("cardnumber missing");
      response.send(false);
  }
  operaatiot.getTapahtumatByKortti(params, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  })
})

router.post('/saldo/', function(request, response) {
  const params = { cardNumber } = request.body;
  if(!cardNumber) {
      console.log("cardnumber missing");
      response.send(false);
  }
  operaatiot.getSaldoByKortti(cardNumber, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  })
})

module.exports = router