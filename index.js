// vim: set expandtab tabstop=2 shiftwidth=2:
'use strict';

var callback = require('nad-bindings')('callback');

var objForCall = {
  cb: function () {
    console.log('objForCall cb()');
    process.nextTick(function () {
    //setImmediate(function () {
      console.log('objForCall nextTick');
    });
  }
}

var objForMakeCallback = {
  cb: function () {
    console.log('objForMakeCallback cb()');
    process.nextTick(function () {
    //setImmediate(function () {
      console.log('objForMakeCallback nextTick');
    });
  }
}

console.log("callback.callFuncViaCall(objForCall)");
callback.callFuncViaCall(objForCall);

console.log("callback.callFuncViaMakeCallback(objForMakeCallback)");
callback.callFuncViaMakeCallback(objForMakeCallback);
