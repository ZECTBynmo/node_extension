//////////////////////////////////////////////////////////////////////////////
//
// ExtensionMain.cpp : Main module source, declares all exports
// Copyright Mike Vegeto
// 
//////////////////////////////////////////////////////////////////////////////

#include <v8.h>
//#pragma comment(lib, "node")
#include <node.h>

#include "MyExtension.h"
#include <string>
#include <stdio.h>
using namespace v8;

Handle<Value> CreateInstance(const Arguments& args) {
    HandleScope scope;
    return scope.Close( MyExtension::MyExtension::NewInstance(args) );
} // end CreateInstance()

void InitAll(Handle<Object> target) {
    MyExtension::MyExtension::Init( target );

    target->Set( String::NewSymbol("MyExtension"), FunctionTemplate::New(CreateInstance)->GetFunction() );
} // end InitAll()

NODE_MODULE( MyExtension, InitAll );
