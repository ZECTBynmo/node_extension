//////////////////////////////////////////////////////////////////////////
// myExtension - main module
//////////////////////////////////////////////////////////////////////////
//
// Main javascript API
/* ----------------------------------------------------------------------
													Object Structures
-------------------------------------------------------------------------
	
*/

//////////////////////////////////////////////////////////////////////////
// Namespace (lol)
var SHOW_DEBUG_PRINTS = true;																		
var log = function(a) { if(SHOW_DEBUG_PRINTS) console.log(a); };	// A log function we can turn off

var MyNativeExtension = require( __dirname + "/build/Release/MyExtension" );


//////////////////////////////////////////////////////////////////////////
// Constructor
function MyExtension() {
	this.native = MyNativeExtension.MyExtension(); // Instantiate our native extension

	return this;
} // end MyExtension();


//////////////////////////////////////////////////////////////////////////
// Returns our main audio processing function
MyExtension.prototype.getHelloWorldString = function() {
	return this.native.getHelloWorldString();
} // end MyExtension.getHelloWorldString()


exports.myExtension = MyExtension;