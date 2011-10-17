#include <v8.h>
#include <node.h>
#include <stdio.h>

using namespace v8;
using namespace node;

namespace {
	struct RoflerArguments {
		inline RoflerArguments(const Arguments& args)
		{
		}
	};

	Handle<Value> Say(const Arguments& args) {
		HandleScope scope;
		const RoflerArguments ra(args);
		printf("rofl\n");
		return Undefined();
	}

	extern "C" void init(Handle<Object> target) {
		HandleScope scope;
		target->Set(String::New("say"), FunctionTemplate::New(Say)->GetFunction());
	}
}


