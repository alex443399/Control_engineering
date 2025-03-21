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
        ;% Auto data (Model_feedback_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Model_feedback_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Model_feedback_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedback_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedback_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 107;
            section.data(107)  = dumData; %prealloc

                    ;% Model_feedback_P.Quantizer1_Interval
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_P.SFunction_P1_Size_k
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Model_feedback_P.SFunction_P1
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 3;

                    ;% Model_feedback_P.SFunction_P2_Size
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 4;

                    ;% Model_feedback_P.SFunction_P2
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% Model_feedback_P.ec_Ebox_P1_Size
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 7;

                    ;% Model_feedback_P.ec_Ebox_P1
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 9;

                    ;% Model_feedback_P.count2rad_Gain
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% Model_feedback_P.Gain1_Gain
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Model_feedback_P.Gain1_Gain_a
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 14;

                    ;% Model_feedback_P.Dctleadlag2_P1_Size
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 15;

                    ;% Model_feedback_P.Dctleadlag2_P1
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 17;

                    ;% Model_feedback_P.Dctleadlag2_P2_Size
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 18;

                    ;% Model_feedback_P.Dctleadlag2_P2
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 20;

                    ;% Model_feedback_P.Dctleadlag2_P3_Size
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 21;

                    ;% Model_feedback_P.Dctleadlag2_P3
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 23;

                    ;% Model_feedback_P.Dctnotch3_P1_Size
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 24;

                    ;% Model_feedback_P.Dctnotch3_P1
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 26;

                    ;% Model_feedback_P.Dctnotch3_P2_Size
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 27;

                    ;% Model_feedback_P.Dctnotch3_P2
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 29;

                    ;% Model_feedback_P.Dctnotch3_P3_Size
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 30;

                    ;% Model_feedback_P.Dctnotch3_P3
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 32;

                    ;% Model_feedback_P.Dctnotch3_P4_Size
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 33;

                    ;% Model_feedback_P.Dctnotch3_P4
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 35;

                    ;% Model_feedback_P.Dctnotch3_P5_Size
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 36;

                    ;% Model_feedback_P.Dctnotch3_P5
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 38;

                    ;% Model_feedback_P.Dctnotch4_P1_Size
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 39;

                    ;% Model_feedback_P.Dctnotch4_P1
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 41;

                    ;% Model_feedback_P.Dctnotch4_P2_Size
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 42;

                    ;% Model_feedback_P.Dctnotch4_P2
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 44;

                    ;% Model_feedback_P.Dctnotch4_P3_Size
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 45;

                    ;% Model_feedback_P.Dctnotch4_P3
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 47;

                    ;% Model_feedback_P.Dctnotch4_P4_Size
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 48;

                    ;% Model_feedback_P.Dctnotch4_P4
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 50;

                    ;% Model_feedback_P.Dctnotch4_P5_Size
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 51;

                    ;% Model_feedback_P.Dctnotch4_P5
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 53;

                    ;% Model_feedback_P.Dctleadlag5_P1_Size
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 54;

                    ;% Model_feedback_P.Dctleadlag5_P1
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 56;

                    ;% Model_feedback_P.Dctleadlag5_P2_Size
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 57;

                    ;% Model_feedback_P.Dctleadlag5_P2
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 59;

                    ;% Model_feedback_P.Dctleadlag5_P3_Size
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 60;

                    ;% Model_feedback_P.Dctleadlag5_P3
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 62;

                    ;% Model_feedback_P.Dct1lowpass6_P1_Size
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 63;

                    ;% Model_feedback_P.Dct1lowpass6_P1
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 65;

                    ;% Model_feedback_P.Dct1lowpass6_P2_Size
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 66;

                    ;% Model_feedback_P.Dct1lowpass6_P2
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 68;

                    ;% Model_feedback_P.Dctnotch7_P1_Size
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 69;

                    ;% Model_feedback_P.Dctnotch7_P1
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 71;

                    ;% Model_feedback_P.Dctnotch7_P2_Size
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 72;

                    ;% Model_feedback_P.Dctnotch7_P2
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 74;

                    ;% Model_feedback_P.Dctnotch7_P3_Size
                    section.data(51).logicalSrcIdx = 56;
                    section.data(51).dtTransOffset = 75;

                    ;% Model_feedback_P.Dctnotch7_P3
                    section.data(52).logicalSrcIdx = 57;
                    section.data(52).dtTransOffset = 77;

                    ;% Model_feedback_P.Dctnotch7_P4_Size
                    section.data(53).logicalSrcIdx = 58;
                    section.data(53).dtTransOffset = 78;

                    ;% Model_feedback_P.Dctnotch7_P4
                    section.data(54).logicalSrcIdx = 59;
                    section.data(54).dtTransOffset = 80;

                    ;% Model_feedback_P.Dctnotch7_P5_Size
                    section.data(55).logicalSrcIdx = 60;
                    section.data(55).dtTransOffset = 81;

                    ;% Model_feedback_P.Dctnotch7_P5
                    section.data(56).logicalSrcIdx = 61;
                    section.data(56).dtTransOffset = 83;

                    ;% Model_feedback_P.Noise_Mean
                    section.data(57).logicalSrcIdx = 62;
                    section.data(57).dtTransOffset = 84;

                    ;% Model_feedback_P.Noise_StdDev
                    section.data(58).logicalSrcIdx = 63;
                    section.data(58).dtTransOffset = 85;

                    ;% Model_feedback_P.Noise_Seed
                    section.data(59).logicalSrcIdx = 64;
                    section.data(59).dtTransOffset = 86;

                    ;% Model_feedback_P.Gain1_Gain_f
                    section.data(60).logicalSrcIdx = 65;
                    section.data(60).dtTransOffset = 87;

                    ;% Model_feedback_P.Dctpd2_P1_Size
                    section.data(61).logicalSrcIdx = 66;
                    section.data(61).dtTransOffset = 88;

                    ;% Model_feedback_P.Dctpd2_P1
                    section.data(62).logicalSrcIdx = 67;
                    section.data(62).dtTransOffset = 90;

                    ;% Model_feedback_P.Dctpd2_P2_Size
                    section.data(63).logicalSrcIdx = 68;
                    section.data(63).dtTransOffset = 91;

                    ;% Model_feedback_P.Dctpd2_P2
                    section.data(64).logicalSrcIdx = 69;
                    section.data(64).dtTransOffset = 93;

                    ;% Model_feedback_P.Dctpd2_P3_Size
                    section.data(65).logicalSrcIdx = 70;
                    section.data(65).dtTransOffset = 94;

                    ;% Model_feedback_P.Dctpd2_P3
                    section.data(66).logicalSrcIdx = 71;
                    section.data(66).dtTransOffset = 96;

                    ;% Model_feedback_P.Dct2lowpass3_P1_Size
                    section.data(67).logicalSrcIdx = 72;
                    section.data(67).dtTransOffset = 97;

                    ;% Model_feedback_P.Dct2lowpass3_P1
                    section.data(68).logicalSrcIdx = 73;
                    section.data(68).dtTransOffset = 99;

                    ;% Model_feedback_P.Dct2lowpass3_P2_Size
                    section.data(69).logicalSrcIdx = 74;
                    section.data(69).dtTransOffset = 100;

                    ;% Model_feedback_P.Dct2lowpass3_P2
                    section.data(70).logicalSrcIdx = 75;
                    section.data(70).dtTransOffset = 102;

                    ;% Model_feedback_P.Dct2lowpass3_P3_Size
                    section.data(71).logicalSrcIdx = 76;
                    section.data(71).dtTransOffset = 103;

                    ;% Model_feedback_P.Dct2lowpass3_P3
                    section.data(72).logicalSrcIdx = 77;
                    section.data(72).dtTransOffset = 105;

                    ;% Model_feedback_P.Dctnotch4_P1_Size_j
                    section.data(73).logicalSrcIdx = 78;
                    section.data(73).dtTransOffset = 106;

                    ;% Model_feedback_P.Dctnotch4_P1_m
                    section.data(74).logicalSrcIdx = 79;
                    section.data(74).dtTransOffset = 108;

                    ;% Model_feedback_P.Dctnotch4_P2_Size_j
                    section.data(75).logicalSrcIdx = 80;
                    section.data(75).dtTransOffset = 109;

                    ;% Model_feedback_P.Dctnotch4_P2_h
                    section.data(76).logicalSrcIdx = 81;
                    section.data(76).dtTransOffset = 111;

                    ;% Model_feedback_P.Dctnotch4_P3_Size_n
                    section.data(77).logicalSrcIdx = 82;
                    section.data(77).dtTransOffset = 112;

                    ;% Model_feedback_P.Dctnotch4_P3_n
                    section.data(78).logicalSrcIdx = 83;
                    section.data(78).dtTransOffset = 114;

                    ;% Model_feedback_P.Dctnotch4_P4_Size_n
                    section.data(79).logicalSrcIdx = 84;
                    section.data(79).dtTransOffset = 115;

                    ;% Model_feedback_P.Dctnotch4_P4_b
                    section.data(80).logicalSrcIdx = 85;
                    section.data(80).dtTransOffset = 117;

                    ;% Model_feedback_P.Dctnotch4_P5_Size_o
                    section.data(81).logicalSrcIdx = 86;
                    section.data(81).dtTransOffset = 118;

                    ;% Model_feedback_P.Dctnotch4_P5_m
                    section.data(82).logicalSrcIdx = 87;
                    section.data(82).dtTransOffset = 120;

                    ;% Model_feedback_P.Dctleadlag5_P1_Size_a
                    section.data(83).logicalSrcIdx = 88;
                    section.data(83).dtTransOffset = 121;

                    ;% Model_feedback_P.Dctleadlag5_P1_n
                    section.data(84).logicalSrcIdx = 89;
                    section.data(84).dtTransOffset = 123;

                    ;% Model_feedback_P.Dctleadlag5_P2_Size_p
                    section.data(85).logicalSrcIdx = 90;
                    section.data(85).dtTransOffset = 124;

                    ;% Model_feedback_P.Dctleadlag5_P2_p
                    section.data(86).logicalSrcIdx = 91;
                    section.data(86).dtTransOffset = 126;

                    ;% Model_feedback_P.Dctleadlag5_P3_Size_b
                    section.data(87).logicalSrcIdx = 92;
                    section.data(87).dtTransOffset = 127;

                    ;% Model_feedback_P.Dctleadlag5_P3_e
                    section.data(88).logicalSrcIdx = 93;
                    section.data(88).dtTransOffset = 129;

                    ;% Model_feedback_P.Dctnotch6_P1_Size
                    section.data(89).logicalSrcIdx = 94;
                    section.data(89).dtTransOffset = 130;

                    ;% Model_feedback_P.Dctnotch6_P1
                    section.data(90).logicalSrcIdx = 95;
                    section.data(90).dtTransOffset = 132;

                    ;% Model_feedback_P.Dctnotch6_P2_Size
                    section.data(91).logicalSrcIdx = 96;
                    section.data(91).dtTransOffset = 133;

                    ;% Model_feedback_P.Dctnotch6_P2
                    section.data(92).logicalSrcIdx = 97;
                    section.data(92).dtTransOffset = 135;

                    ;% Model_feedback_P.Dctnotch6_P3_Size
                    section.data(93).logicalSrcIdx = 98;
                    section.data(93).dtTransOffset = 136;

                    ;% Model_feedback_P.Dctnotch6_P3
                    section.data(94).logicalSrcIdx = 99;
                    section.data(94).dtTransOffset = 138;

                    ;% Model_feedback_P.Dctnotch6_P4_Size
                    section.data(95).logicalSrcIdx = 100;
                    section.data(95).dtTransOffset = 139;

                    ;% Model_feedback_P.Dctnotch6_P4
                    section.data(96).logicalSrcIdx = 101;
                    section.data(96).dtTransOffset = 141;

                    ;% Model_feedback_P.Dctnotch6_P5_Size
                    section.data(97).logicalSrcIdx = 102;
                    section.data(97).dtTransOffset = 142;

                    ;% Model_feedback_P.Dctnotch6_P5
                    section.data(98).logicalSrcIdx = 103;
                    section.data(98).dtTransOffset = 144;

                    ;% Model_feedback_P.Gain2_Gain
                    section.data(99).logicalSrcIdx = 104;
                    section.data(99).dtTransOffset = 145;

                    ;% Model_feedback_P.Constant_Value
                    section.data(100).logicalSrcIdx = 105;
                    section.data(100).dtTransOffset = 149;

                    ;% Model_feedback_P.Constant1_Value
                    section.data(101).logicalSrcIdx = 106;
                    section.data(101).dtTransOffset = 151;

                    ;% Model_feedback_P.Constant2_Value
                    section.data(102).logicalSrcIdx = 107;
                    section.data(102).dtTransOffset = 159;

                    ;% Model_feedback_P.Gain_Gain
                    section.data(103).logicalSrcIdx = 108;
                    section.data(103).dtTransOffset = 160;

                    ;% Model_feedback_P.Saturation_UpperSat
                    section.data(104).logicalSrcIdx = 109;
                    section.data(104).dtTransOffset = 161;

                    ;% Model_feedback_P.Saturation_LowerSat
                    section.data(105).logicalSrcIdx = 110;
                    section.data(105).dtTransOffset = 162;

                    ;% Model_feedback_P.Saturation_UpperSat_d
                    section.data(106).logicalSrcIdx = 111;
                    section.data(106).dtTransOffset = 163;

                    ;% Model_feedback_P.Saturation_LowerSat_e
                    section.data(107).logicalSrcIdx = 112;
                    section.data(107).dtTransOffset = 164;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedback_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 113;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_P.ManualSwitch_CurrentSetting
                    section.data(2).logicalSrcIdx = 114;
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
        ;% Auto data (Model_feedback_B)
        ;%
            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% Model_feedback_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Model_feedback_B.ref
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Model_feedback_B.SFunction_b
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Model_feedback_B.ec_Ebox_o1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% Model_feedback_B.ec_Ebox_o2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% Model_feedback_B.ec_Ebox_o3
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% Model_feedback_B.e
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 18;

                    ;% Model_feedback_B.Gain1
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Model_feedback_B.Gain1_p
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20;

                    ;% Model_feedback_B.Dctleadlag2
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 21;

                    ;% Model_feedback_B.Dctnotch3
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 22;

                    ;% Model_feedback_B.Dctnotch4
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 23;

                    ;% Model_feedback_B.Dctleadlag5
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 24;

                    ;% Model_feedback_B.Dct1lowpass6
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 25;

                    ;% Model_feedback_B.Dctnotch7
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 26;

                    ;% Model_feedback_B.Noise
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 27;

                    ;% Model_feedback_B.Gain1_l
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 28;

                    ;% Model_feedback_B.Dctpd2
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 29;

                    ;% Model_feedback_B.Dct2lowpass3
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 30;

                    ;% Model_feedback_B.Dctnotch4_a
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 31;

                    ;% Model_feedback_B.Dctleadlag5_c
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 32;

                    ;% Model_feedback_B.Dctnotch6
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 33;

                    ;% Model_feedback_B.Gain2
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 34;

                    ;% Model_feedback_B.Constant1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 38;

                    ;% Model_feedback_B.Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 46;

                    ;% Model_feedback_B.Saturation
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 48;

                    ;% Model_feedback_B.Downsample
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 50;

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
        ;% Auto data (Model_feedback_DW)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% Model_feedback_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_DW.NextOutput
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Model_feedback_DW.fileID
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Model_feedback_DW.SFunction_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Model_feedback_DW.Dctleadlag2_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 55;

                    ;% Model_feedback_DW.Dctnotch3_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 57;

                    ;% Model_feedback_DW.Dctnotch4_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 61;

                    ;% Model_feedback_DW.Dctleadlag5_RWORK
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 65;

                    ;% Model_feedback_DW.Dct1lowpass6_RWORK
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 67;

                    ;% Model_feedback_DW.Dctnotch7_RWORK
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 69;

                    ;% Model_feedback_DW.Dctpd2_RWORK
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 73;

                    ;% Model_feedback_DW.Dct2lowpass3_RWORK
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 75;

                    ;% Model_feedback_DW.Dctnotch4_RWORK_n
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 79;

                    ;% Model_feedback_DW.Dctleadlag5_RWORK_f
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 83;

                    ;% Model_feedback_DW.Dctnotch6_RWORK
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 85;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedback_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Model_feedback_DW.RandSeed
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Model_feedback_DW.NS
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedback_DW.NF
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedback_DW.busy
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedback_DW.eml_autoflush
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Model_feedback_DW.eml_openfiles
                    section.data(1).logicalSrcIdx = 22;
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


    targMap.checksum0 = 3843785733;
    targMap.checksum1 = 4190881784;
    targMap.checksum2 = 2710023559;
    targMap.checksum3 = 3675515654;

