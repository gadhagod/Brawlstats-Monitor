cd ~ # go to home diretory
git clone https://github.com/gadhagod/Brawlstats-Monitor # clone the repo
cd Brawlstats-Monitor # go to cloned repo
sudo apt-get install arduino # install Arduino
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh  # install arduino cli
export PATH=$PATH:/home/pi/Brawlstats-Monitor/bin # add path
arduino-cli config init # initialize CLI configuration
arduino-cli core update-index # update cores
arduino-cli core install arduino:avr # install arduino cli core
arduino-cli lib install "Adafruit SSD1306" # install OLED library
pip3 install -r requirements.txt # install brawlstats and Jinja
mkdir sketch # make sketch folder
