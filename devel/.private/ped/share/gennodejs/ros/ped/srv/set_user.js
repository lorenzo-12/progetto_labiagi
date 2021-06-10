// Auto-generated. Do not edit!

// (in-package ped.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class set_userRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.azione = null;
      this.name = null;
      this.x = null;
      this.y = null;
    }
    else {
      if (initObj.hasOwnProperty('azione')) {
        this.azione = initObj.azione
      }
      else {
        this.azione = '';
      }
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type set_userRequest
    // Serialize message field [azione]
    bufferOffset = _serializer.string(obj.azione, buffer, bufferOffset);
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float32(obj.y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type set_userRequest
    let len;
    let data = new set_userRequest(null);
    // Deserialize message field [azione]
    data.azione = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.azione.length;
    length += object.name.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ped/set_userRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b93ed8e36ebd42da6a2eca7ccdcd5b60';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string azione
    string name
    float32 x
    float32 y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new set_userRequest(null);
    if (msg.azione !== undefined) {
      resolved.azione = msg.azione;
    }
    else {
      resolved.azione = ''
    }

    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    return resolved;
    }
};

class set_userResponse {
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
        this.ret = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type set_userResponse
    // Serialize message field [ret]
    bufferOffset = _serializer.string(obj.ret, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type set_userResponse
    let len;
    let data = new set_userResponse(null);
    // Deserialize message field [ret]
    data.ret = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.ret.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ped/set_userResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c7030931189f40243cd08ed0e4c0bac7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string ret
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new set_userResponse(null);
    if (msg.ret !== undefined) {
      resolved.ret = msg.ret;
    }
    else {
      resolved.ret = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: set_userRequest,
  Response: set_userResponse,
  md5sum() { return '22d2aef14551e2abcdbc9a7b477b5fa6'; },
  datatype() { return 'ped/set_user'; }
};
