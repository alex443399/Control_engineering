    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Model_feedforward_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Model_feedforward_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Model_feedforward_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedforward_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 50;
            section.data(50)  = dumData; %prealloc

                    ;% Model_feedforward_P.Gain1_Gain
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_P.Quantizer1_Interval
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 3;

                    ;% Model_feedforward_P.SFunction_P1_Size_k
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 4;

                    ;% Model_feedforward_P.SFunction_P1
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 6;

                    ;% Model_feedforward_P.SFunction_P2_Size
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 7;

                    ;% Model_feedforward_P.SFunction_P2
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 9;

                    ;% Model_feedforward_P.ec_Ebox_P1_Size
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 10;

                    ;% Model_feedforward_P.ec_Ebox_P1
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 12;

                    ;% Model_feedforward_P.count2rad_Gain
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 13;

                    ;% Model_feedforward_P.Gain1_Gain_l
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 14;

                    ;% Model_feedforward_P.Dctpd2_P1_Size
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 15;

                    ;% Model_feedforward_P.Dctpd2_P1
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 17;

                    ;% Model_feedforward_P.Dctpd2_P2_Size
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 18;

                    ;% Model_feedforward_P.Dctpd2_P2
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 20;

                    ;% Model_feedforward_P.Dctpd2_P3_Size
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 21;

                    ;% Model_feedforward_P.Dctpd2_P3
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 23;

                    ;% Model_feedforward_P.Dct2lowpass3_P1_Size
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 24;

                    ;% Model_feedforward_P.Dct2lowpass3_P1
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 26;

                    ;% Model_feedforward_P.Dct2lowpass3_P2_Size
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 27;

                    ;% Model_feedforward_P.Dct2lowpass3_P2
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 29;

                    ;% Model_feedforward_P.Dct2lowpass3_P3_Size
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 30;

                    ;% Model_feedforward_P.Dct2lowpass3_P3
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 32;

                    ;% Model_feedforward_P.Dctleadlag4_P1_Size
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 33;

                    ;% Model_feedforward_P.Dctleadlag4_P1
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 35;

                    ;% Model_feedforward_P.Dctleadlag4_P2_Size
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 36;

                    ;% Model_feedforward_P.Dctleadlag4_P2
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 38;

                    ;% Model_feedforward_P.Dctleadlag4_P3_Size
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 39;

                    ;% Model_feedforward_P.Dctleadlag4_P3
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 41;

                    ;% Model_feedforward_P.Dctnotch5_P1_Size
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 42;

                    ;% Model_feedforward_P.Dctnotch5_P1
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 44;

                    ;% Model_feedforward_P.Dctnotch5_P2_Size
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 45;

                    ;% Model_feedforward_P.Dctnotch5_P2
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 47;

                    ;% Model_feedforward_P.Dctnotch5_P3_Size
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 48;

                    ;% Model_feedforward_P.Dctnotch5_P3
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 50;

                    ;% Model_feedforward_P.Dctnotch5_P4_Size
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 51;

                    ;% Model_feedforward_P.Dctnotch5_P4
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 53;

                    ;% Model_feedforward_P.Dctnotch5_P5_Size
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 54;

                    ;% Model_feedforward_P.Dctnotch5_P5
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 56;

                    ;% Model_feedforward_P.Noise_Mean
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 57;

                    ;% Model_feedforward_P.Noise_StdDev
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 58;

                    ;% Model_feedforward_P.Noise_Seed
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 59;

                    ;% Model_feedforward_P.Gain2_Gain
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 60;

                    ;% Model_feedforward_P.Constant_Value
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 64;

                    ;% Model_feedforward_P.Constant1_Value
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 66;

                    ;% Model_feedforward_P.Constant2_Value
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 74;

                    ;% Model_feedforward_P.Gain_Gain
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 75;

                    ;% Model_feedforward_P.Saturation_UpperSat
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 76;

                    ;% Model_feedforward_P.Saturation_LowerSat
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 77;

                    ;% Model_feedforward_P.Saturation_UpperSat_d
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 78;

                    ;% Model_feedforward_P.Saturation_LowerSat_e
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 79;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedforward_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_P.Selectencoder_CurrentSetting
                    section.data(2).logicalSrcIdx = 57;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Model_feedforward_B)
        ;%
            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% Model_feedforward_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Model_feedforward_B.SFunction_b
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Model_feedforward_B.ec_Ebox_o1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Model_feedforward_B.ec_Ebox_o2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% Model_feedforward_B.ec_Ebox_o3
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

                    ;% Model_feedforward_B.Gain1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 17;

                    ;% Model_feedforward_B.Dctpd2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 18;

                    ;% Model_feedforward_B.Dct2lowpass3
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Model_feedforward_B.Dctleadlag4
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20;

                    ;% Model_feedforward_B.Dctnotch5
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 21;

                    ;% Model_feedforward_B.Noise
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 22;

                    ;% Model_feedforward_B.Gain2
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 23;

                    ;% Model_feedforward_B.Constant1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 27;

                    ;% Model_feedforward_B.Gain
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 35;

                    ;% Model_feedforward_B.Saturation
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Model_feedforward_DW)
        ;%
            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Model_feedforward_DW.NextOutput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_DW.fileID
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Model_feedforward_DW.SFunction_RWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Model_feedforward_DW.Dctpd2_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 52;

                    ;% Model_feedforward_DW.Dct2lowpass3_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 54;

                    ;% Model_feedforward_DW.Dctleadlag4_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 58;

                    ;% Model_feedforward_DW.Dctnotch5_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 60;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedforward_DW.RandSeed
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedforward_DW.NS
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_DW.NF
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_DW.busy
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedforward_DW.eml_openfiles
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 149769691;
    targMap.checksum1 = 254669655;
    targMap.checksum2 = 4168494185;
    targMap.checksum3 = 737528693;

