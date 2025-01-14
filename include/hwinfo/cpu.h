// Copyright Leon Freist
// Author Leon Freist <freist@informatik.uni-freiburg.de>

#include <string>
#include <vector>

#ifndef HWINFO_CPU_H_
#define HWINFO_CPU_H_


namespace hwinfo {

class CPU {
 public:
  CPU();
  ~CPU();

  std::string modelName() { return _modelName; }
  std::string vendor() { return _vendor; }
  [[nodiscard]] int cacheSizeBytes() const { return _cacheSizeBytes; }
  [[nodiscard]] int numPhysicalCores() const { return _numPhysicalCores; }
  [[nodiscard]] int numLogicalCores() const { return _numLogicalCores; }
  [[nodiscard]] int maxClockSpeedMHz() const { return _maxClockSpeedMHz; }
  [[nodiscard]] int regularClockSpeedMHz() const { return _regularClockSpeedMHz; }
  [[nodiscard]] int minClockSpeedMHz() const { return _minClockSpeedMHz; }
  [[nodiscard]] bool isHHT() const { return _isHTT; }
  [[nodiscard]] bool isSSE() const { return _isSSE; }
  [[nodiscard]] bool isSSE2() const { return _isSSE2; }
  [[nodiscard]] bool isSSE3() const { return _isSSE3; }
  [[nodiscard]] bool isSSE41() const { return _isSSE41; }
  [[nodiscard]] bool isSSE42() const {return _isSSE42; }
  [[nodiscard]] bool isAVX() const { return _isAVX; }
  [[nodiscard]] bool isAVX2() const { return _isAVX2; }

  [[nodiscard]] std::vector<int> currentClockSpeedMHz() const;

  static int currentClockSpeedMHz(short coreId);

  static std::string getModelName();
  static std::string getVendor();
  static int getNumPhysicalCores();
  static int getNumLogicalCores();
  static int getMaxClockSpeedMHz();
  static int getRegularClockSpeedMHz();
  static int getMinClockSpeedMHz();
  static int getCacheSizeBytes();
 private:

  std::string _modelName;
  int _numPhysicalCores = -1;
  int _numLogicalCores = -1;
  int _maxClockSpeedMHz = -1;
  int _regularClockSpeedMHz = -1;
  int _minClockSpeedMHz = -1;
  std::string _vendor;
  int _cacheSizeBytes = -1;
  int _numSMT = -1;
  bool _isHTT = false;
  bool _isSSE = false;
  bool _isSSE2 = false;
  bool _isSSE3 = false;
  bool _isSSE41 = false;
  bool _isSSE42 = false;
  bool _isAVX = false;
  bool _isAVX2 = false;
};

}  // namespace hwinfo

#endif //HWINFO_CPU_H_
