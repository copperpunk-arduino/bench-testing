#define debug_port Serial
#define data_port Serial1

void setup()
{
    debug_port.begin(115200);
    data_port.begin(115200);
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (data_port.available())
    {
        unsigned long current_time_ms = millis();
        char buffer[20];
        sprintf(buffer, "[%lu]: %x\n", current_time_ms, data_port.read());
        debug_port.print(buffer);
    }
}