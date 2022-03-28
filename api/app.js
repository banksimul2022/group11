const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const indexRouter = require('./routes/index');
const asiakasRouter = require('./routes/asiakas');
const tiliRouter = require('./routes/tili');
<<<<<<< HEAD
const tilitapahtumatRouter = require('./routes/tilitapahtumat')
=======
const korttiRouter = require('./routes/kortti');
>>>>>>> 81ebe44141e37b520001580c24bbb8ae04fb853c

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
<<<<<<< HEAD
app.use('/tilitapahtumat', tilitapahtumatRouter)
=======
app.use('/kortti',korttiRouter)
>>>>>>> 81ebe44141e37b520001580c24bbb8ae04fb853c

module.exports = app;
