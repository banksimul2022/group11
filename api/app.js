const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const authenticateToken = require('./custom_modules/authentication')

const indexRouter = require('./routes/index');
const loginRouter = require('./routes/login');
const asiakasRouter = require('./routes/asiakas');
const tiliRouter = require('./routes/tili');
const tilitapahtumaRouter = require('./routes/tilitapahtuma');
const korttiRouter = require('./routes/kortti');
const asiakastiliRouter = require('./routes/asiakastili');
const operaatiotRouter = require('./routes/operaatiot');

const app = express();

app.use(express.static(path.join(__dirname, 'public')));
app.use(express.json());
app.use(logger('dev'));
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());

app.use('/', indexRouter);
app.use('/login', loginRouter);
//app.use(authenticateToken);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtuma', tilitapahtumaRouter);
app.use('/kortti', korttiRouter);
app.use('/asiakastili', asiakastiliRouter);
app.use('/operaatiot', operaatiotRouter);

const unknownEndpoint = (request, response) => {
    response.status(404).send({ error: 'unknown endpoint' });
}
app.use(unknownEndpoint);

const errorHandler = (error, request, response, next) => {
    console.error(error.message);
  
    if (error.name === 'CastError') {
      return response.status(400).send({ error: 'malformatted id' });
    }
  
    next(error)
  }
app.use(errorHandler);

module.exports = app;
