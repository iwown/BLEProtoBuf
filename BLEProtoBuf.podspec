Pod::Spec.new do |s|

s.name         = 'BLEProtoBuf'

s.version      = "0.0.1"

s.summary      = 'Iwown BLE protocol for D2'

s.license      = 'MIT'

s.author       = { "xuezou" => "377949550@qq.com" }

s.homepage     = 'https://github.com/xuezou/BLEProtoBuf'

s.source       = { :git => "https://github.com/xuezou/BLEProtoBuf.git", :tag => s.version}

s.platform     = :ios

s.ios.deployment_target = "9.0"

s.frameworks = 'Foundation'

s.vendored_frameworks = 'BLEProtocBuf/BLEProtocBuff.framework'

s.requires_arc = true

s.dependency 'BLEMidAutumn'
s.dependency 'Protobuf'

end