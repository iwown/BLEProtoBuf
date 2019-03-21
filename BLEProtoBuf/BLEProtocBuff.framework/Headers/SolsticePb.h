//
//  SolsticePb.h
//  BLEProtocBuff
//
//  Created by A$CE on 2019/3/18.
//  Copyright © 2019年 Iwown. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    /**! PBSDType_it ; data indextable*/
    PBSDType_it_health = 0x01,
    PBSDType_it_gnss,
    PBSDType_it_ecg,
    PBSDType_it_ppg,
    PBSDType_it_rri,
    
    /**! PBSDType_dt ; data detail<##>*/
    PBSDType_dt_health = 0x11,
    PBSDType_dt_gnss,
    PBSDType_dt_ecg,
    PBSDType_dt_ppg,
    PBSDType_dt_rri,
    
    PBSDType_summary = 0x70,
}PBSDType;

@class PBPersonalInfo;
@class PBBloodPressureConf;
@class PBHrAlarmConf;
@protocol SolsticePb <NSObject>

/**! Config of personal info setting in device, like height, weight, age and forth. Device has no way for correct arithmetic If not setting*/
- (void)setPersonalInfo:(PBPersonalInfo *)pi;

/**! Blood pressure calibration setting method<##>*/
- (void)setBloodPresureConf:(PBBloodPressureConf *)bpConf;

/**! Exercise heart rate alert setting*/
- (void)setEHRWParam:(PBHrAlarmConf *)ehrwp;

/**! Mehtod to sysc data .
 @see startSpecialData:startSeq:endSeq:*/
- (void)startSpecialData:(PBSDType)sdType;
/**
 Synchronize the data method, incoming data from the updateNormalHealthDataInfo: method to get your specified time or type of data, the data is packaged in a fixed manner, based on the amount of data, some of the data we are packaged together, But there are some data as a separate data package
 
 @param sdType Type
 @param startSeq Some devices rely on Seq for their data continuity and require that they be passed in when they are synchronized. If you get startSeq & endSeq in your device info is 0, this means your device does not need this seq, Please also 0 value as a parameter to synchronize data, which is ok, or you can use the method does not need to pass in this parameter
 @see startSpecialData:withDate:
 @param endSeq Similar to startSeq.
 */
- (void)startSpecialData:(PBSDType)sdType startSeq:(NSInteger)startSeq endSeq:(NSInteger)endSeq;
@end

NS_ASSUME_NONNULL_END
