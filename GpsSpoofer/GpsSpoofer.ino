constexpr int kNavPvtLength = 100;
constexpr byte kNavPvtMsg[] = {181, 98, 1, 7, 92, 0, 44, 29, 173, 19, 230, 7, 12, 21, 19, 41, 34, 247, 233, 3, 0, 0, 88, 111, 222, 17, 3, 131, 234, 18, 54, 59, 209, 182, 26, 13, 222, 22, 253, 16, 0, 0, 85, 131, 0, 0, 241, 0, 0, 0, 156, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 60, 101, 231, 1, 10, 0, 0, 0, 199, 8, 84, 0, 127, 0, 2, 0, 92, 65, 79, 33, 0, 0, 0, 0, 0, 0, 0, 0, 192, 225};

constexpr int kRelPosNedLength = 72;
constexpr byte kRelPosNedMsg[] = {181, 98, 1, 60, 64, 0, 1, 0, 0, 0, 200, 28, 173, 19, 111, 0, 0, 0, 253, 255, 255, 255, 0, 0, 0, 0, 111, 0, 0, 0, 8, 90, 34, 2, 0, 0, 0, 0, 16, 179, 227, 22, 100, 0, 0, 0, 100, 0, 0, 0, 100, 0, 0, 0, 100, 0, 0, 0, 60, 201, 0, 0, 0, 0, 0, 0, 55, 1, 0, 0, 9, 102};

constexpr long kSendIntervalMs = 100;

unsigned long _prev_send_time_ms;

#define data_port Serial

void setup() {
  // put your setup code here, to run once:
  data_port.begin(230400);
  _prev_send_time_ms = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time_ms = millis();
  if (current_time_ms - _prev_send_time_ms > kSendIntervalMs) {
    _prev_send_time_ms = current_time_ms;
    data_port.write(kNavPvtMsg, kNavPvtLength);
    data_port.write(kRelPosNedMsg, kRelPosNedLength);
  }
}`
