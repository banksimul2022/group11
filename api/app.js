const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const indexRouter = require('./routes/index');
const asiakasRouter = require('./routes/asiakas');
const tiliRouter = require('./routes/tili');
const tilitapahtumatRouter = require('./routes/tilitapahtumat')
const korttiRouter = require('./routes/kortti');
const asiakastili = require('./routes/asiakastili');

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter)
app.use('/kortti',korttiRouter)
app.use('/asiakastili', asiakastili)
module.exports = app;
