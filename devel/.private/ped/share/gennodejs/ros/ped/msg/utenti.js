// Auto-generated. Do not edit!

// (in-package ped.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class utenti {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.name = null;
      this.option = null;
      this.pick = null;
      this.delivery = null;
      this.response = null;
      this.stato = null;
    }
    else {
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('option')) {
        this.option = initObj.option
      }
      else {
        this.option = '';
      }
      if (initObj.hasOwnProperty('pick')) {
        this.pick = initObj.pick
      }
      else {
        this.pick = '';
      }
      if (initObj.hasOwnProperty('delivery')) {
        this.delivery = initObj.delivery
      }
      else {
        this.delivery = '';
      }
      if (initObj.hasOwnProperty('response')) {
        this.response = initObj.response
      }
      else {
        this.response = '';
      }
      if (initObj.hasOwnProperty('stato')) {
        this.stato = initObj.stato
      }
      else {
        this.stato = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type utenti
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [option]
    bufferOffset = _serializer.string(obj.option, buffer, bufferOffset);
    // Serialize message field [pick]
    bufferOffset = _serializer.string(obj.pick, buffer, bufferOffset);
    // Serialize message field [delivery]
    bufferOffset = _serializer.string(obj.delivery, buffer, bufferOffset);
    // Serialize message field [response]
    bufferOffset = _serializer.string(obj.response, buffer, bufferOffset);
    // Serialize message field [stato]
    bufferOffset = _serializer.string(obj.stato, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type utenti
    let len;
    let data = new utenti(null);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [option]
    data.option = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [pick]
    data.pick = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [delivery]
    data.delivery = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [response]
    data.response = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [stato]
    data.stato = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    length += object.option.length;
    length += object.pick.length;
    length += object.delivery.length;
    length += object.response.length;
    length += object.stato.length;
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ped/utenti';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eb76f3f6b8ca9967faa9c0f02b8c1ef7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string name
    string option
    string pick
    string delivery
    string response
    string stato
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new utenti(null);
    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.option !== undefined) {
      resolved.option = msg.option;
    }
    else {
      resolved.option = ''
    }

    if (msg.pick !== undefined) {
      resolved.pick = msg.pick;
    }
    else {
      resolved.pick = ''
    }

    if (msg.delivery !== undefined) {
      resolved.delivery = msg.delivery;
    }
    else {
      resolved.delivery = ''
    }

    if (msg.response !== undefined) {
      resolved.response = msg.response;
    }
    else {
      resolved.response = ''
    }

    if (msg.stato !== undefined) {
      resolved.stato = msg.stato;
    }
    else {
      resolved.stato = ''
    }

    return resolved;
    }
};

module.exports = utenti;
