// Auto-generated. Do not edit!

// (in-package message_tests.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ChangerateRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.newrate = null;
    }
    else {
      if (initObj.hasOwnProperty('newrate')) {
        this.newrate = initObj.newrate
      }
      else {
        this.newrate = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ChangerateRequest
    // Serialize message field [newrate]
    bufferOffset = _serializer.float64(obj.newrate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ChangerateRequest
    let len;
    let data = new ChangerateRequest(null);
    // Deserialize message field [newrate]
    data.newrate = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'message_tests/ChangerateRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '16f24c25ebb8fdfdbd54328d251e49b8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 newrate
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ChangerateRequest(null);
    if (msg.newrate !== undefined) {
      resolved.newrate = msg.newrate;
    }
    else {
      resolved.newrate = 0.0
    }

    return resolved;
    }
};

class ChangerateResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ret = null;
    }
    else {
      if (initObj.hasOwnProperty('ret')) {
        this.ret = initObj.ret
      }
      else {
        this.ret = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ChangerateResponse
    // Serialize message field [ret]
    bufferOffset = _serializer.bool(obj.ret, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ChangerateResponse
    let len;
    let data = new ChangerateResponse(null);
    // Deserialize message field [ret]
    data.ret = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'message_tests/ChangerateResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e2cc9e9d8c464550830df49c160979ad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool ret
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ChangerateResponse(null);
    if (msg.ret !== undefined) {
      resolved.ret = msg.ret;
    }
    else {
      resolved.ret = false
    }

    return resolved;
    }
};

module.exports = {
  Request: ChangerateRequest,
  Response: ChangerateResponse,
  md5sum() { return '4c8b4fd3f5e2b2736a3c66de5e015351'; },
  datatype() { return 'message_tests/Changerate'; }
};
