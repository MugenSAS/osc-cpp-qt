osc-cpp-qt
==========

OSC (Open Sound Control) library for C++ using Qt

This library is dedicated to writing or read osc messages.

### Writing Messages
```C
	OscMessageComposer msg( "/the/osc/address");
    msg.pushBool( true );
	msg.pushInt32( 99 );
    QByteArray* formattedMsg = msg.getBytes();
```


### Reading Messages
```C
	OscReader reader(rawMessage);
	OscMessage* msg = reader.getMessage();
	
	QString address = msg->getAddress();	// Get the message address
	bool myBool = msg->getValue( 0 ).toBoolean();
	int myInt = msg->getValue( 1 ).toInteger();
	
	delete msg;	
```


### Tests
Current osc.test.pro is using GoogleTest library.
It is available at [GoogleTest](https://github.com/google/googletest.git)

