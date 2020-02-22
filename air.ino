#define         MG_PIN                       (A5)
#define         DATA_PIN                     (2)
#define         DC_GAIN                      (8.5)
#define         READ_SAMPLE_INTERVAL         (50)
#define         READ_SAMPLE_TIMES            (5)
#define         ZERO_POINT_VOLTAGE           (0.280)
#define         REACTION_VOLTAGE             (0.030)

float CO2_CURVE[3] = {2.602, ZERO_POINT_VOLTAGE, (REACTION_VOLTAGE/(2.602-3))};

float readSensor(int mg_pin)
{
  int i;
  float v=0;

  for (i=0;i<READ_SAMPLE_TIMES;i++) {
      v += analogRead(mg_pin);
      delay(READ_SAMPLE_INTERVAL);
  }
  v = (v/READ_SAMPLE_TIMES)*5/1024;
  return v;
}

int asPercentage(float volts)
{
  return pow(10, ((volts/DC_GAIN)-CO2_CURVE[1])/CO2_CURVE[2]+CO2_CURVE[0]);
}

void captureAir() {
  int percentage;
  percentage = asPercentage(volts);
  volts = readSensor(MG_PIN);
  outputAir += percentage;
}
