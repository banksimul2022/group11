const express = require('express');
const router = express.Router()
const lukitse = require('../models/lukitse_model')


router.post('/', function(request, response) {
  const params = { cardNumber, lockStatus } = request.body;
  lukitse.changeLockCard(params, function(err, dbResult) {
    if (err) {
      response.json({ error: err.sqlMessage });
    } else {
      response.json({ result: `Cardnumber ${cardNumber} lock status changed to ${lockStatus == 1 ? 'locked' : 'unlocked'}` });
    }
  })
})

module.exports = router