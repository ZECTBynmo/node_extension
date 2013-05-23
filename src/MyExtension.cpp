#include "MyExtension.h"
//////////////////////////////////////////////////////////////////////////////
//
// MyExtension.cpp: Core functionality
// Copyright Mike Vegeto
// 
//////////////////////////////////////////////////////////////////////////////
// DevStudio!namespace MyExtension DevStudio!class MyExtension
#include "MyExtension.h"
#include "v8.h"
using namespace v8;

Persistent<Function> MyExtension::MyExtension::constructor;

//////////////////////////////////////////////////////////////////////////////
/*! Initialize */
MyExtension::MyExtension::MyExtension() :
	m_strHelloWorld("Hello JavaScript Land") {
	
} // end MyExtension::MyExtension()


//////////////////////////////////////////////////////////////////////////////
/*! Initialize our node object */
void MyExtension::MyExtension::Init( v8::Handle<v8::Object> target ) {
	// Prepare constructor template
	Local<FunctionTemplate> functionTemplate = FunctionTemplate::New( MyExtension::New );
	functionTemplate->SetClassName( String::NewSymbol("MyExtension") );
	functionTemplate->InstanceTemplate()->SetInternalFieldCount( 1 );

	// Setup functions here
	functionTemplate->PrototypeTemplate()->Set( String::NewSymbol("getHelloWorldString"), FunctionTemplate::New(MyExtension::getHelloWorldString)->GetFunction() );

	constructor = Persistent<Function>::New( functionTemplate->GetFunction() );
} // end MyExtension::Init()


//////////////////////////////////////////////////////////////////////////////
/*! Create a new instance of the audio engine */
v8::Handle<v8::Value> MyExtension::MyExtension::NewInstance( const v8::Arguments& args ) {
	HandleScope scope;

	unsigned argc = args.Length();

	if( argc > 2 ) 
		argc = 2;

	Handle<Value>* argv = new Handle<Value>[argc];

	argv[0] = args[0];
	if( argc > 1 )
		argv[1] = args[1];

	Local<Object> instance = constructor->NewInstance( argc, argv );

	return scope.Close( instance );
} // end MyExtension::NewInstance()


//////////////////////////////////////////////////////////////////////////////
/*! Create a v8 object */
v8::Handle<v8::Value> MyExtension::MyExtension::New( const v8::Arguments& args ) {
	HandleScope scope;

	Local<Function> callback;
	Local<Object> options;

	MyExtension* pInstance = new MyExtension();
	pInstance->Wrap( args.This() );

	return scope.Close( args.This() );
} // end MyExtension::New()


//////////////////////////////////////////////////////////////////////////////
/*! Returns a the contents of the class' hello world string */
v8::Handle<v8::Value> MyExtension::MyExtension::getHelloWorldString( const v8::Arguments& args ) {
	HandleScope scope;

	MyExtension* pEngine = MyExtension::Unwrap<MyExtension>( args.This() );

	return scope.Close( String::New(pEngine->m_strHelloWorld.c_str()) );
} // end MyExtension::getHelloWorldString()
