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
  const { cardNumber } = request.body;
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

router.post('/nosto/', function(request, response) {
  const params = { cardNumber, amount } = request.body;
  if(!cardNumber || !amount) {
      console.log("withdraw parameters missing");
      response.send(false);
  }
  operaatiot.createWithdraw(params, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  })
})

router.post('/siirto/', function(request, response) {
  const params = { cardNumber, amount, targetCardNumber } = request.body;
  if(!cardNumber || !amount || !targetCardNumber) {
      console.log("transaction parameters missing");
      response.send(false);
  }
  operaatiot.createTransaction(params, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  })
})

module.exports = router