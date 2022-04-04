const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const indexRouter = require('./routes/index');
const loginRouter = require('./routes/login');
const asiakasRouter = require('./routes/asiakas');
const tiliRouter = require('./routes/tili');
const tilitapahtumaRouter = require('./routes/tilitapahtuma')
const korttiRouter = require('./routes/kortti');
const asiakastiliRouter = require('./routes/asiakastili');

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtuma', tilitapahtumaRouter)
app.use('/kortti',korttiRouter)
app.use('/asiakastili', asiakastiliRouter)
module.exports = app;
