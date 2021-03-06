const express = require('express');
const path = require('path');
const logger = require('morgan');

const authenticateToken = require('./custom_modules/authentication')

const loginRouter = require('./routes/login');
const lukitseRouter = require('./routes/lukitse')
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

app.use('/login', loginRouter);
app.use('/lukitse', lukitseRouter);
app.use(authenticateToken);
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

module.exports = app;
