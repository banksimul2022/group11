const { response } = require('express')
const express = require('express')
const router = express.Router()
const operaatiot = require('../models/operaatiot_model')

router.get('/tilitapahtumat/:cardNumber', function(request, response) {
  operaatiot.getTapahtumatByKortti(request.params.cardNumber, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  })
})

router.get('/saldo/:cardNumber', function(request, response) {
  operaatiot.getSaldoByKortti(request.params.cardNumber, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  })
})

module.exports = router