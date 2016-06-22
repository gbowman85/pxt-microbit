#include "pxt.h"
#include "MESEvents.h"

using namespace pxt;

/**
 * Support for additional Bluetooth services.
 */
//% color=#0082FB weight=20
namespace bluetooth {
    /**
    *  Starts the Bluetooth IO pin service.
    */
    //% help=bluetooth/start-io-pin-service
    //% blockId=bluetooth_start_io_pin_service block="bluetooth io pin service" blockGap=8
    void startIOPinService() {
        new MicroBitIOPinService(*uBit.ble, uBit.io);
    }

    /**
    *  Starts the Bluetooth LED service
    */
    //% help=bluetooth/start-led-service
    //% blockId=bluetooth_start_led_service block="bluetooth led service" blockGap=8
    void startLEDService() {
        new MicroBitLEDService(*uBit.ble, uBit.display);
    }

    /**
    *  Starts the Bluetooth temperature service
    */
    //% help=bluetooth/start-temperature-service
    //% blockId=bluetooth_start_temperature_service block="bluetooth temperature service" blockGap=8
    void startTemperatureService() {    
        new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);        
    }

    /**
    *  Starts the Bluetooth magnetometer service
    */
    //% help=bluetooth/start-magnetometer-service
    //% blockId=bluetooth_start_magnetometer_service block="bluetooth magnetometer service" blockGap=8
    void startMagnetometerService() {    
        new MicroBitMagnetometerService(*uBit.ble, uBit.compass); 
    }

    /**
    *  Starts the Bluetooth accelerometer service
    */
    //% help=bluetooth/start-accelerometer-service
    //% blockId=bluetooth_start_accelerometer_service block="bluetooth accelerometer service" blockGap=8
    void startAccelerometerService() {
        new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);        
    }

    /**
    *  Starts the Bluetooth button service
    */
    //% help=bluetooth/start-button-service
    //% blockId=bluetooth_start_button_service block="bluetooth button service" blockGap=8
    void startButtonService() {
        new MicroBitButtonService(*uBit.ble);      
    }
    
     /**
     * Register code to run when the micro:bit is connected to over Bluetooth
     * @param body Code to run when a Bluetooth connection is established
     */
    //% help=bluetooth/on-bluetooth-connected
    //% blockId=bluetooth_on_connected block="on bluetooth connected"
    void onBluetoothConnected(Action body) {
        registerWithDal(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, body);
    }    

     /**
     * Register code to run when a bluetooth connection to the micro:bit is lost
     * @param body Code to run when a Bluetooth connection is lost
     */
    //% help=bluetooth/on-bluetooth-disconnected
    //% blockId=bluetooth_on_disconnected block="on bluetooth disconnected"
    void onBluetoothDisconnected(Action body) {
        registerWithDal(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, body);
    }    
  
  
}