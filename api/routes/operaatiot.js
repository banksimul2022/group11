const express = require('express')
const router = express.Router()
const operaatiot = require('../models/operaatiot_model')

router.post('/tilitapahtumat/', function(request, response) {
  const params = { cardNumber, offset = 0, noOfRows = 10 } = request.body;
  operaatiot.getTapahtumatByKortti(params, function(err, dbResult) {
    if (err) {
      response.json({ error: err.sqlMessage });
    } else {
      response.json({ result: dbResult[0] });
    }
  })
})

router.post('/saldo/', function(request, response) {
  const { cardNumber } = request.body;
  operaatiot.getSaldoByKortti(cardNumber, function(err, dbResult) {
    if (err) {
      response.json({ error: err.sqlMessage });
    } else {
      response.json({ result: JSON.stringify(dbResult[0][0].saldo) });
    }
  })
})

router.post('/nosto/', function(request, response) {
  const params = { cardNumber, amount } = request.body;
  operaatiot.createWithdraw(params, function(err, dbResult) {
    if (err) {
      response.json({ error: err.sqlMessage });
    } else {
      response.json({ result: dbResult });
    }
  })
})

router.post('/siirto/', function(request, response) {
  const params = { cardNumber, amount, targetCardNumber } = request.body;
  operaatiot.createTransaction(params, function(err, dbResult) {
    if (err) {
      response.json({ error: err.sqlMessage });
    } else {
      response.json({ result: dbResult });
    }
  })
})

module.exports = router