const { response } = require('express')
const express = require('express')
const router = express.Router()
const tilitapahtumat = require('../models/tilitapahtumat_model')

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    tilitapahtumat.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err)
      } else {
        response.json(dbResult)
      }
    })
  } else {
    tilitapahtumat.get(function(err, dbResult) {
      if (err) {
        response.json(err)
      } else {
        response.json(dbResult)
      }
    })
  }
})

router.get('/:aikaleima?', 
function(req, res) {
    if (req.params.aikaleima) {
        tilitapahtumat.getByAikaleima(req.params.aikaleima, function(err, dbres) {
            if (err) {
                response.json(err)
            } else {
                response.json(dbres)
            }
        })
    } else {
        tilitapahtumat.get(function(err, dbres) {
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
  tilitapahtumat.add(request.body, function(err, count) {
    if (err) {
      response.json(err)
    } else {
      response.json(request.body) 
    }
  })
})

router.delete('/:id', 
function(request, response) {
  tilitapahtumat.delete(request.params.id, function(err, count) {
    if (err) {
      response.json(err)
    } else {
      response.json(count)
    }
  })
})

router.put('/:id', 
function(request, response) {
  tilitapahtumat.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err)
    } else {
      response.json(dbResult)
    }
  })
})

module.exports = router