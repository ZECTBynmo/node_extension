var MyExtension = require("./myExtension").myExtension;

var myExtension = MyExtension();

console.log( myExtension.native.getHelloWorldString() );