
Does your microcontroller need to control a high voltage item, like a 12V LED strip, while needing to be powered as well? Do you want to avoid having multiple power adapters for your project and microcontroller? The [MOSFET Power Switch and Buck Regulator (Low-Side)](https://www.sparkfun.com/products/23979) is one of those products that we needed ourselves at SparkFun, so we figured other folks may have the same problem. Power the board with up to 12V and control up to 10A, all while providing a sweet 3.3V to your control board.

<center>
<div class="grid cards" style="width:500px;" markdown>

-   <a href="https://www.sparkfun.com/products/23979">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/parts/2/4/3/0/3/COM-23979-MOSFET-Power-Switch-Feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun MOSFET Power Switch and Buck Regulator (Low-Side)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/23979">
      <b>SparkFun MOSFET Power Switch and Buck Regulator (Low-Side)</b>
      <br />
      COM-23979
      <br />
      <center>[Purchase from SparkFun :fontawesome-solid-cart-plus:](https://www.sparkfun.com/products/23979){ .md-button .md-button--primary }</center>
    </a>

</div>
</center>

In this tutorial, we will go over the hardware, how to connect to the board, and provide some Arduino examples.



### Required Materials

To follow along with this tutorial, you will need the following materials. We made a general list below since there are several options available to connect to the MOSFET Power Control and Buck Regulator (Low-Side). We'll list the specific parts used in each of the examples later in the tutorial. You may not need everything though depending on what you have. Add it to your cart, read through the guide, and adjust the cart as necessary.

* 1x Microcontroller
* 1x USB Cable
* 1x SparkFun MOSFET Power Switch and Buck Regulator (Low-Side)
* 1x SparkFun Mini Screwdriver
* 1x Pack of Jumper Wires
* 1x High Power Load
* 1x Wall Adapter



#### Microcontroller

For the scope of the tutorial, we will be using an Arduino microcontroller. In this case, we will be using the SparkFun IoT RedBoard - ESP32. You can use any Arduino microcontroller with digital or PWM pins. Make sure to also include a USB cable that is compatible with your microcontroller.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/19177">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/8/8/0/0/ESP32_03.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun IoT RedBoard - ESP32 Development Board">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/19177">
      <b>SparkFun IoT RedBoard - ESP32 Development Board</b>
      <br />
      WRL-19177
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15092">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/3/9/8/4/15425-Reversible_USB_A_to_C_Cable_-_0.8m-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Reversible USB A to C Cable - 0.8m">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15092">
      <b>Reversible USB A to C Cable - 0.8m</b>
      <br />
      CAB-15092
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>

!!! tip
    The 3.3V output from the MOSFET Power Switch and Buck Regulator (Low-Side) provides another alternative to power microcontrollers that may not be able to accept higher voltages. For example, most of the [Thing Plus Development Boards](https://www.sparkfun.com/thing_plus) only accept a maximum of 6V at their VIN pin, and they most operate at 3.3V. So this board is especially handy in those use-cases. Additionally, even though the Arduino Pro Mini can accept up to 12V, this will require its onboard linear regulator to work very had to regulate that voltage down to 3.3V. Thus, this MOSFET Power Switch and Buck Regulator (Low-Side) would be the "cooler" choice.

!!! note
    The tutorial focuses on using a microcontroller with Arduino. However, if your microcontroller has a digital or PWM, you can also control the N-channel MOSFET controller as well! You can also use this using a micro:bit with MakeCode or Raspberry Pi's RP2040 microcontroller with MicroPython!



#### 12V LEDs

The MOSFET Power Switch and Buck Regulator (Low-Side) can control 12V LEDs. For users with a 12V RGB LED strip, you can control one channel.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/12021">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/8/5/4/9/12021-04.jpg" style="width:140px; height:140px; object-fit:contain;" alt="LED RGB Strip - Bare (1m)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12021">
      <b>LED RGB Strip - Bare (1m)</b>
      <br />
      COM-12021
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



#### Motors

There are a variety of motors with different ratings. Below are a few different motors that you could use for users that just need a motor to spin in one direction.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11270">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/6/9/0/2/11270-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Blower - Squirrel Cage (12V)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11270">
      <b>Blower - Squirrel Cage (12V)</b>
      <br />
      COM-11270
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

-   <a href="https://www.sparkfun.com/products/11696">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/7/8/6/0/11696-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Hobby Motor - Gear">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11696">
      <b>Hobby Motor - Gear</b>
      <br />
      ROB-11696
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15277">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/7/5/3/15277-Planetary_Gearmotor-02a.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Planetary Gearmotor - 140RPM">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15277">
      <b>Planetary Gearmotor - 140RPM</b>
      <br />
      ROB-15277
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/10398">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/4/8/5/4/10398-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Vacuum Pump - 12V">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/10398">
      <b>Vacuum Pump - 12V</b>
      <br />
      ROB-10398
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/19222">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/8/8/4/9/19222-Liquid_Pump_-_500GPH__12V_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Liquid Pump - 500GPH (12V)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/19222">
      <b>Liquid Pump - 500GPH (12V)</b>
      <br />
      ROB-19222
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



#### Solenoid

Check below if you need a latching solenoid to lock a box of your secret stash of cookies, solenoid valve to water some plants, or even have the small solenoid tap a glass cup of water! Similar to the motors, each solenoid will have a different rating.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15324">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/8/4/3/15324-Latching_solenoid-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solenoid - 12V (Latch / Lock)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15324">
      <b>Solenoid - 12V (Latch / Lock)</b>
      <br />
      ROB-15324
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

-   <a href="https://www.sparkfun.com/products/10456">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/4/9/4/5/10456-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="12V Solenoid Valve - 3/4 Inch">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/10456">
      <b>12V Solenoid Valve - 3/4"</b>
      <br />
      ROB-10456
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11015">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/6/3/2/2/11015-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solenoid - 5V (Small)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11015">
      <b>Solenoid - 5V (Small)</b>
      <br />
      ROB-11015
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



#### Heating Element

Feeling cold? Try adding a small heating pad to warm up your hands or even a horse bit for an early morning ride! Or maybe you want to make a mini-refrigerator to keep your drinks cool with a thermoelectric cooler.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11288">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/6/9/5/9/11288-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Heating Pad - 5x10cm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11288">
      <b>Heating Pad - 5x10cm</b>
      <br />
      COM-11288
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

-   <a href="https://www.sparkfun.com/products/11289">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/6/9/6/0/11289-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Heating Pad - 5x15cm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11289">
      <b>Heating Pad - 5x15cm</b>
      <br />
      COM-11289
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15082">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/4/3/2/15082-Thermoelectric_Cooler-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Thermoelectric Cooler">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15082">
      <b>Thermoelectric Cooler</b>
      <br />
      COM-15082
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



#### Heatsink

Is your MOSFET getting too hot to the touch? You can add a small heatsink to [help dissipate some heat](https://learn.sparkfun.com/tutorials/understanding-thermal-resistance). The small heatsink listed below fits the exposed ground plane on the back of the board. If you need a slightly bigger heat sink, there is also the copper heatsink (note that it's a little bigger than the size of the exposed ground plane). You can also use the copper heatsink with the thermoelectric cooler listed above.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11510">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/5/7/0/4/10746-02a.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Heating Pad - 5x10cm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11510">
      <b>Small Heatsink</b>
      <br />
      PRT-11510
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/17054">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/6/0/0/0/17054-Thermal_Tape_4x4in._Square-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Heating Pad - 5x15cm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/17054">
      <b>Thermal Tape 4x4" Square</b>
      <br />
      PRT-17054
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

-   <a href="https://www.sparkfun.com/products/18704">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/8/2/3/7/18704-1.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Heatsink - 13.20 x 12.10 mm (Copper)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/18704">
      <b>Heatsink - 13.20 x 12.10 mm (Copper)</b>
      <br />
      PRT-18704
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



#### Power Supply

The power supply that you use will depend on your load and project requirements. For example, the [small solenoid](https://www.sparkfun.com/products/11015) is rated for 5V while the [latching solenoid](https://www.sparkfun.com/products/15324) is rated for 12V. Below are a [few power supplies available in SparkFun's catalog](https://www.sparkfun.com/categories/308). Not sure which power supply that you need? Try grabbing the power supply sample kit!


<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/19194">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/8/8/1/8/19194-SparkFun_Power_Supply_Sample_Kit-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Power Supply Sample Kit">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/19194">
      <b>SparkFun Power Supply Sample Kit</b>
      <br />
      KIT-19194
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15313">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/3/8/1/6/TOL-15313-1.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wall Adapter Power Supply - 12VDC, 600mA (Barrel Jack)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15313">
      <b>Wall Adapter Power Supply - 12VDC, 600mA (Barrel Jack)</b>
      <br />
      TOL-15313
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15314">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/8/1/7/TOL-15314-1.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wall Adapter Power Supply - 9VDC, 650mA (Barrel Jack)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15313">
      <b>Wall Adapter Power Supply - 9VDC, 650mA (Barrel Jack)</b>
      <br />
      TOL-15314
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15312">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/8/1/5/TOL-15312-1.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wall Adapter Power Supply - 5VDC, 2A (Barrel Jack)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15312">
      <b>Wall Adapter Power Supply - 5VDC, 2A (Barrel Jack)</b>
      <br />
      TOL-15313
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>

If you decided to connect a few MOSFET Power Switch and Buck Regulators (Low-Side) together using the same power supply, you may want to include the following barrel jack adapters.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/10287">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/4/6/8/3/10287-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="DC Barrel Jack Adapter - Male">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/10287">
      <b>DC Barrel Jack Adapter - Male</b>
      <br />
      PRT-10287
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/10288">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/4/6/8/4/10288-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="DC Barrel Jack Adapter - Female">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/10288">
      <b>DC Barrel Jack Adapter - Female</b>
      <br />
      PRT-10288
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>

#### Prototyping Accessories _(Optional)_

We've designed the board to allow for an easy connection with the rest of the system using M/M jumper wires. Depending on your application, you can solder header pins or you may need an additional breadboard. Below are a few prototyping accessories that you may want to consider.

<div class="grid cards col-4" markdown>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/12045">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/8/6/2/8/12045-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Breadboard - Mini Modular (Blue)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12045">
      <b>Breadboard - Mini Modular (Blue)</b>
      <br />
      PRT-12045
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/12002">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/8/5/0/3/12002-Breadboard_-_Self-Adhesive__White_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Breadboard - Self-Adhesive (White)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12002">
      <b>Breadboard - Self-Adhesive (White)</b>
      <br />
      PRT-12002
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/115">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/0/5/00115-03-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Female Headers">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/115">
      <b>Female Headers</b>
      <br />
      PRT-00115
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/116">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/0/6/00116-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Break Away Headers - Straight">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/116">
      <b>Break Away Headers - Straight</b>
      <br />
      PRT-00116
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9140">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/5/5/7/09140-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Jumper Wires Premium 6" M/F Pack of 10">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9140">
      <b>Jumper Wires Premium 6" M/F Pack of 10</b>
      <br>
      PRT-09140
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/8431">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/1/8/1/JumperWire-Male-01-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Jumper Wires Premium 6" M/M Pack of 10">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/8431">
      <b>Jumper Wires Premium 6" M/M Pack of 10</b>
      <br />
      PRT-08431
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11026">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/3/7/0/4/11026-Jumper_Wires_Standard_7in._M_M_-_30_AWG__30_Pack_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Jumper Wires Standard 7" M/M - 30 AWG (30 Pack)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11026">
      <b>Jumper Wires Standard 7" M/M - 30 AWG (30 Pack)</b>
      <br />
      PRT-11026
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



#### Tools _(Optional)_

Besides the mini screwdriver, there may be other tools that you may need. For a secure connection, you will need to solder two wires between your microcontroller and the breakout board. This requires some assembly and soldering. You may already have a few of these items but if not, the tools and hardware below help with that assembly.

<div class="grid cards hide col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9146">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/2/5/6/3/09146-SparkFun_Mini_Screwdriver-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Mini Screwdriver">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9146">
      <b>SparkFun Mini Screwdriver</b>
      <br />
      TOL-09146
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11375">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/7/1/2/0/11375-Hook-Up_Wire_-_Assortment__Solid_Core__22_AWG_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Hook-Up Wire - Assortment (Stranded, 22 AWG)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11375">
      <b>Hook-Up Wire - Assortment (Stranded, 22 AWG)</b>
      <br />
      PRT-11375
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/22263">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/2/2/0/1/22263-_TOL_Wire_Stripper-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22263">
      <b>Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)</b>
      <br />
      TOL-22263
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/24063">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/parts/2/4/3/8/5/KIT-24063-PINECIL-Soldering-Iron-Kit-Feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="PINECIL Soldering Iron Kit">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/24063">
      <b>PINECIL Soldering Iron Kit</b>
      <br />
      TOL-24063
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9163">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/5/8/7/09162-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solder Lead Free - 15-gram Tube">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9163">
      <b>Solder Lead Free - 15-gram Tube</b>
      <br>
      TOL-09163
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



#### You Will Also Need

If you decide to do some "magic," try grabbing the following with the squirrel cage blower.

* Ping Pong Ball



### Suggested Reading

If you aren’t familiar with the following concepts, we also recommend checking out a few of these tutorials before continuing.

<div class="grid cards hide col-4" markdown>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/transistors">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/9/3/intro.png" style="width:264px; height:148px; object-fit:contain;" alt="Transistors">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/transistors">
      <b>Transistors</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/diodes">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/6/8/diode_2.PNG" style="width:264px; height:148px; object-fit:contain;" alt="Diodes">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/diodes">
      <b>Diodes</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/logic-levels/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/Input_Output_Logic_Level_Tolerances_tutorial_tile.png" style="width:264px; height:148px; object-fit:contain;" alt="Logic Levels">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/logic-levels/all">
      <b>Logic Levels</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->

-   <a href="https://learn.sparkfun.com/tutorials/iot-redboard-esp32-development-board-hookup-guide">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/2/2/5/7/285808434_548438690244031_7008413248633042033_n.jpg" style="width:264px; height:148px; object-fit:contain;" alt="IoT RedBoard ESP32 Development Board Hookup Guide">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/iot-redboard-esp32-development-board-hookup-guide">
      <b>IoT RedBoard ESP32 Development Board Hookup Guide</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/motors-and-selecting-the-right-one/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/4/c/6/4/7/52a22672757b7f511d8b456b.jpg"style="width:264px; height:148px; object-fit:contain;" alt="Motors and Selecting the Right One">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/motors-and-selecting-the-right-one/all">
      <b>Motors and Selecting the Right One</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/non-addressable-rgb-led-strip-hookup-guide">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/learn_tutorials/7/3/1/Non-Addressable_RGB_LED_Strip_Custom_Color_Cycling.gif"style="width:264px; height:148px; object-fit:contain;" alt="Non-Addressable RGB LED Strip Hookup Guide">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/non-addressable-rgb-led-strip-hookup-guide">
      <b>Non-Addressable RGB LED Strip Hookup Guide</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/1/2/terminalThumb.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Terminal Basics">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <b>Serial Terminal Basics</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <b>How to Solder: Through Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/working-with-wire/how-to-strip-a-wirel">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/0/5/0/0/f/5138de3cce395fbb1b000002.JPG"style="width:264px; height:148px; object-fit:contain;" alt="Working with Wire">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/working-with-wire/how-to-strip-a-wire">
      <b>Working with Wire</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/how-to-work-with-jumper-pads-and-pcb-traces/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/6/6/4/PCB_TraceCutLumenati.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Work with Jumper Pads and PCB Traces">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-work-with-jumper-pads-and-pcb-traces/all">
      <b>How to Work with Jumper Pads and PCB Traces</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/how-to-power-a-project/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/3/6/Bench_Power_Supply.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Power a Project">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-power-a-project/all">
      <b>How to Power a Project</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>
