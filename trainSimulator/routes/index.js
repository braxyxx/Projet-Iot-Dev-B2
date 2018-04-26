var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index.ejs');
});

var SerialPort = require("serialport");


var serialPort = new SerialPort("COM7", {
  baudRate: 9600,
});



serialPort.on("open", function () {
  console.log('open');
  serialPort.on('data', function(data) {
    console.log(data);
  });
});


module.exports = router;
