// const systemClock = require("./build/Release/system-clock.node");
// module.exports = systemClock;

// Will load a compiled build if present or a prebuild.
// If no build if found it will throw an exception
const binding = require("node-gyp-build")(__dirname);

module.exports = binding;
