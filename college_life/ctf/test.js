const atob = require('atob');
var lineReader = require('readline').createInterface({
  input: require('fs').createReadStream('./easyctf/data.txt')
});

lineReader.on('line', function (line) {
  console.log(atob(line));
});