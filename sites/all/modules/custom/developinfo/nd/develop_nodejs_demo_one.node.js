// exports.myText = 'hello text module';

// var demoModule = require('./develop_nodejs_demo_module.node.js');
// console.log('fn text is ' + demoModule.myText);

/**
 * read JSON file
 */
// File System, File I/O, use this module do require('fs')
// 1
// var fs = require('fs');
// fs.readFile('./develop_nodejs_demo_file.json', 'utf-8', (err, data2) => {
//   if (err) throw err;

//   data2 = JSON.parse(data2);
//   console.log(data2.userName);
// });

// // 2
// var data = require('./develop_nodejs_demo_file.json');
// console.log(data.userName);

/**
 * Accessing directories and list all folder name and file name, like ls -la
 */
// var fs = require('fs');
// fs.readdir('/var/www/html', (err, data) => {
//   console.log(data);
// });


/**
 * writing to a json file
 */
var fs = require('fs');
// json format
var tomString = '{ "name": "Tom" }';
fs.writeFile('tom.json', tomString);

// object formmat, and converts to JSON
var mikeString = {
  name: 'mike'
};
mikeJson = JSON.stringify(mikeString);
fs.writeFile('mike.json', mikeJson);
