require('dotenv').config()

const mysql = require('mysql');

// Use LOCAL_DATABASE in development. Use DATABASE in production
const connection = process.env.NODE_ENV === 'development' 
  ? mysql.createPool({
    host: process.env.LOCAL_DATABASE_HOST,
    user: process.env.LOCAL_DATABASE_USER,
    password: process.env.LOCAL_DATABASE_PASSWORD,
    database: process.env.LOCAL_DATABASE_DATABASE
  })
  : mysql.createPool({
    host: process.env.DATABASE_HOST,
    user: process.env.DATABASE_USER,
    password: process.env.DATABASE_PASSWORD,
    database: process.env.DATABASE_DATABASE
  });
module.exports = connection;