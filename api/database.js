const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'bankuser',
  password: 'bankpass',
  database: 'banksimuldb'
});
module.exports = connection;