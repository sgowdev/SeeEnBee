# Question Sheet / Coding Exercise

### What is a situation where you had to solve a tough engineering problem?
When I was working at SciAps, one of our products was an embedded Android powered XRF analyzer that collected data via an xray tube.
The code that triggered the xray resided inside a hardware service implemented in C++.
This same hardware service module also contained the algorithms needed to process it.
Once the data was processed, the results were sent to the Android application via AIDL (as the hardware service ran in its own process).
  * What was the problem?
    * The results (e.g. concentration of Aluminum, Copper, Nickel, etc.) were inconsistent test after test, despite shooting the same materials
    * Debugging was not an option, as the algorithms existed outside the Android app's process
  * What did you do to solve it?
    * I extracted the C++ algorithm code into the main Android app compilation path via the NDK
    * This was tricky, as I had to modify several parts of the code (mostly caused by differing standard libaries found in AOSP versus NDK)
    * I saved the raw spectral data for reprocessing after the migration to the NDK to gaurantee I did not break any algorithms
  * What was the outcome?
    * Once the code was moved, we were able to debug the data processing code to find and fix bugs
    * I was also able to cross-compile the algorithm code for desktop use, which allowed our physicists to modify it, effectively contributing to the Android codebase, without ever touching the Android project
    * Once the algorithm code was running inside the same process as the apk, the only thing preventing us from running the app in an avd emulator was the xray tube itself, so I implemented a mock version of the hardware service that was data driven. This allowed us to work and hire remotely, as the hardware dependency was removed.

### An enterprise company is interested in building a mobile android app.  You are hired to do the job. What are the considerations and tradeoffs that you would consider to do the job?
  * Is an iOS app also required? If so, a hybrid approach may be more appropriate (e.g. Flutter) unless:
    * Performance is of utmost importance
    * App is expected to take advantage of latest Android/iOS features as soon as they are introduced (takes time to bridge new native features)
    * App needs to have platform-specific UI/UX
  * Does the entire app need to be built from scratch?
    * Use of open source libraries can greatly speed up project development, but bugs can also be introduced by the online community
  * How much existing code can be leveraged if any?
    * Sharing code across multiple apps is a great way to guarantee consistency
    * Code that has already been proven to successfully serve your users is less risky than new code (e.g. networking code, ui components, algorithms, etc.)
  * What is the minimum Android API level needed to support?
    * Newer APIs cannot safely be used when supporting older versions of Android
    * Older versions of Android require the use of compatibility libraries, which add to the apk size
  * Will the app require the use of location data? If so, how precise does it need to be?
    * Requesting the most accurate location possible requires a fine tuned algorithm to prevent excessive battery drain
    * Otherwise, obtaining a location within 10km accuracy consumes less power
    * General location data can be collected from the cache without any additional processing (assuming other apps have requested location recently)
  * What types of data will the app handle? Sensitive data requires sophisticated encryption algorithms for storage and transmission
  * How will we authenticate your users? Is two-factor required?
  * When does the app need to launch? Can we launch in stages beginning with a minimum feature set (MVP)?

### Coding
Project consists of a Stack class, a MinStack child class, a Parentheses Validator util class, and 2 test functions
* Simply open and run SeeEnBee.xcodeproj on your Mac via Xcode,
* compile and run main.cpp via command line interface (e.g. GCC),
* or run a 210 line single file version of the project here: http://tpcg.io/XKU6UQ (click the Execute button)

### Resume
Hosted here:
https://registry.jsonresume.org/sgowdev
