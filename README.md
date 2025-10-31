## Pokemon ZA ShinyHunt

This project allows you to run automated scripts using Arduino Uno R3 (or other ATmega16u2-based device) for Pokemon ZA automated shiny hunting.

### Usage

1. **Build the firmware**
   First run ```make clean``` to clear existing `.hex` file if exists.

   Then, run one of the following commands to build with a specific script:
   ```sh
   make bench_loop
   make wild_area_common
   make restaurant_fight
   ```
   This will compile the firmware with the selected automation script.

2. **Flash to Device**  
   Use your preferred AVR programmer to flash the resulting `.hex` file to your Arduino Uno R3.

   For how to flash the `.hex` file to Arduino Uno R3, check [Updating the Atmega8U2 and 16U2 on an Uno or Mega2560 using DFU](https://www.arduino.cc/en/Hacking/DFUProgramming8U2).

3. **Connect to Switch**  
   Plug the device into your Nintendo Switch. It will be recognized as a Pokken Controller and execute the selected automation script.

### Scripts

- Before plug in the device, make sure to disconnect all other controllers

- **bench_loop**: Automates repeated bench interactions for day/night switch. 
1.  Manually rest in the bench and wait for loading finished, then do not move and plug in the device

- **wild_area_common**: Automates repeated teleporting to the wild area and enter.
1.  Put your character facing the entry of wild area, then plug in the device.

- **RestaurantFight**: Automates farming restaurant fights for 1000 fights required for Mable's Research.
1.  Have active pokemon with attack move in right slot (A).
2.  Facing restaurant reception, then then plug in the device.

You can add new scripts by creating additional `.c` files in the [`Scripts/`](Scripts/) directory and updating the makefile as needed.

### License

- Project code: [MIT License](LICENSE)
- LUFA library: [LUFA License](LUFA_LICENSE)

### Credits and References

- Thanks to progmem for the original implementation: [GitHub - progmem/Switch-Fightstick](https://github.com/progmem/Switch-Fightstick)
- Inspired from [GitHub - Almtr/Switch-Fightstick](https://github.com/shinyquagsire23/Switch-Fightstick) for the original pokemon modules, this repo is created based on his work.
- Other references:
- [GitHub - shinyquagsire23/Switch-Fightstick](https://github.com/shinyquagsire23/Switch-Fightstick)
- [GitHub - bertrandom/snowball-thrower](https://github.com/bertrandom/snowball-thrower)
- [GitHub - kidGodzilla/woff-grinder](https://github.com/kidGodzilla/woff-grinder)
- [GitHub - ebith/Switch-Fightstick](https://github.com/ebith/Switch-Fightstick)