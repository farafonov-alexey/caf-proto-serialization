# CAF Protobuf class serialization issue

##Prereqs
* OS: Windows 10 x64
* Toolchain: MinGW-x64
* Installed Protobuf libs at $ENV{PROTOBUF_DIR_${ARCH}}

##Issue
Compilation error at 
```
add_message_type<Test>("Test");
```
While
```
add_message_type<OtherTest>("OtherTest"); // this is OK
```
with plain struct compiling fine.

