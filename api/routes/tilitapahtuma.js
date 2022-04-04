const { response } = require('express')
const express = require('express')
const router = express.Router()
const tilitapahtuma = require('../models/tilitapahtuma_model')

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    tilitapahtuma.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err)
      } else {
        response.json(dbResult)
      }
    })
  } else {
    tilitapahtuma.get(function(err, dbResult) {
      if (err) {
        response.json(err)
      } else {
        response.json(dbResult)
      }
    })
  }
})

router.get('/:idkortti?', 
function(req, res) {
  if (req.params.idkortti) {
    tilitapahtuma.getByTili(req.params.idkortti, function (err, dbres) {
      if (err) {
        res.json(err)
      } else {
        res.json(dbres)
      }
    })
  }
})

router.get('/:aikaleima?', 
function(req, res) {
    if (req.params.aikaleima) {
        tilitapahtuma.getByAikaleima(req.params.aikaleima, req.params.idkortti, function(err, dbres) {
            if (err) {
                response.json(err)
            } else {
                response.json(dbres)
            }
        })
    } else {
        tilitapahtuma.get(function(err, dbres) {
            if (err) {
                response.json(err)
            } else {
                response.json(dbres)
            }
        })
    }
})

router.post('/', 
function(request, response) {
  tilitapahtuma.add(request.body, function(err, count) {
    if (err) {
      response.json(err)
    } else {
      response.json(request.body) 
    }
  })
})

router.delete('/:id', 
function(request, response) {
  tilitapahtuma.delete(request.params.id, function(err, count) {
    if (err) {
      response.json(err)
    } else {
      response.json(count)
    }
  })
})

router.put('/:id', 
function(request, response) {
  tilitapahtuma.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err)
    } else {
      response.json(dbResult)
    }
  })
})

module.exports = router