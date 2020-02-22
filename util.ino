void calculateData() {
  outputAir = outputAir / loops;
  outputSound = outputSound / loops;
  outputMotion = outputMotion / loops;
  outputLight = outputLight / loops;
}

void resetData() {
  outputAir = 0;
  outputMotion = 0;
  outputSound = 0;
  outputLight = 0;
  loops = 0;
}
