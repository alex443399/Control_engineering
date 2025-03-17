addpath('Model')
addpath('Measurements')
clear all
clc
%% Load the things (Performance measurements.mat)
%% c1, no FF
error = measurements_reference(:,1);
acc = measurements_reference(:,2);
velocity = measurements_reference(:,3);

sample_i = 66412;
sample_f = 113555;
error_period = error(sample_i:sample_f);
acc_period = acc(sample_i:sample_f);
velocity_period = velocity(sample_i:sample_f);
constant_velocity_stroke = acc_period==0 & velocity_period ~= 0;
error_constant_velocity = error_period(constant_velocity_stroke);
%% c1, yes FF
error_c1_yesFF = measure_control_stab_yesFF(:,1);
acc_c1_yesFF = measure_control_stab_yesFF(:,2);
velocity_c1_yesFF = measure_control_stab_yesFF(:,3);

error_period_c1_yesFF = error_c1_yesFF(32883:80026);
acc_period_c1_yesFF = acc_c1_yesFF(32883:80026);
velocity_period_c1_yesFF = velocity_c1_yesFF(32883:80026);
constant_velocity_stroke_c1_yesFF = acc_period_c1_yesFF==0 & velocity_period_c1_yesFF ~= 0;

error_constant_velocity_c1_yesFF = error_period_c1_yesFF(constant_velocity_stroke_c1_yesFF);
%% c2, yes FF
error_c2_yesFF = measure_control_FF_yesFF(:,1);
acc_c2_yesFF = measure_control_FF_yesFF(:,2);
velocity_c2_yesFF = measure_control_FF_yesFF(:,3);

error_period_c2_yesFF = error_c2_yesFF(25377:72520);
acc_period_c2_yesFF = acc_c2_yesFF(25377:72520);
velocity_period_c2_yesFF = velocity_c2_yesFF(25377:72520);
constant_velocity_stroke_c2_yesFF = acc_period_c2_yesFF==0 & velocity_period_c2_yesFF ~= 0;

error_constant_velocity_c2_yesFF = error_period_c2_yesFF(constant_velocity_stroke_c2_yesFF);
%%
plot(error_constant_velocity)
hold on
plot(error_constant_velocity_c1_yesFF)
hold on
plot(error_constant_velocity_c2_yesFF)
hold off