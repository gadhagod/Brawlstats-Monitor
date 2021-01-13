#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // screen width
#define SCREEN_HEIGHT 32 // screen hieght
#define TOGGLE_BUTTON 11 // toggle button
#define OLED_RESET 4 // optional reset button
int state;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // initilize screen

void setup() {
    pinMode(TOGGLE_BUTTON, INPUT_PULLUP);
    state = 1;
    Serial.begin(9600); // begin serial monitor
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println("SSD1306 allocation failed");
        for(;;); // repeat forever if allocation failed
    }
}

void loop() {
    int read_button = digitalRead(TOGGLE_BUTTON);
    if (read_button == LOW) {
        state = state + 1;
        if (state == 8) {
            state = 1;
        }
    }
    if (state == 1) {
        display_txt("Trophies:\n{{ '{:,}'.format(player.trophies) }}");
    }
    if (state == 2) {
        display_txt("Brawlers:\n{{ brawlers }}");
    }
    if (state == 3) {
        display_txt("Solo wins:\n{{ '{:,}'.format(player.solo_victories) }}");
    }
    if (state == 4) {
        display_txt("Duo wins:\n{{ '{:,}'.format(player.duo_victories) }}");
    }
    if (state == 5) {
        display_txt("3v3 wins:\n{{ '{:,}'.format(player.team_victories) }}");
    }
    if (state == 6) {
        display_txt("XP level:\n{{ player.exp_level }}");
    }
    if (state == 7) {
        {% if player.power_play_points == None %}   
            display_txt("Power playpts: 0"); // new line automatically inserted
        {% else %}
            display_txt("Power play pts:{{ player.power_play_points }}");
        {% endif %}
    }
    delay(150);
}

void display_txt(String input) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(input); // data is inserted
    display.display();
}