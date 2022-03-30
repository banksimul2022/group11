const express = require("express");
const router = express.Router();
const asiakastili = require("../models/asiakastili_model");

router.get("/", function (request, response) {
  asiakastili.get(function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get("/:id?", function (request, response) {
  if (!request.params.id) return;
  asiakastili.getById(request.params.id, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get("/asiakas/:id?", function (request, response) {
  if (!request.params.id) return;
  asiakastili.getByIdAsiakas(request.params.id, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get("/tili/:id?", function (request, response) {
  if (!request.params.id) return;
  asiakastili.getByIdTili(request.params.id, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post("/", function (request, response) {
  asiakastili.add(request.body, function (err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete("/:id", function (request, response) {
  asiakastili.delete(request.params.id, function (err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(count);
    }
  });
});

router.put("/:id", function (request, response) {
  asiakastili.update(request.params.id, request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;
