addpath('Model')
addpath('Measurements')
clear all
close all
%% Load the things (Performance measurements.mat)
load("Performance measurements.mat")

error_K_stab_no_ff = get_relevant_error(measurements_reference, 66412+1691, 113555);
error_K_stab_yes_ff = get_relevant_error(measure_control_stab_yesFF, 32883+845, 80026);
error_K_ff_yes_ff = get_relevant_error(measure_control_FF_yesFF, 25377+845, 72520);


plot((1:length(error_K_stab_no_ff))/4000, error_K_stab_no_ff)
hold on
plot((1:length(error_K_stab_yes_ff))/4000, error_K_stab_yes_ff)
hold on
plot((1:length(error_K_ff_yes_ff))/4000, error_K_ff_yes_ff)
hold on
fill([21884 23571 23571 21884]/4000,[-.4 -.4 .5 .5],[235/255 235/255 235/255],'LineStyle',"none")
hold on
fill([45455 46299 46299 45455]/4000,[-.4 -.4 .5 .5],[235/255 235/255 235/255],'LineStyle',"none")
hold off
legend("K_{stab} without FF", "K_{stab} with FF", "K_{ff} with FF", "velocity not constant")
ylim([-.4,.5])
ylabel('error (rad)')
xlabel('Time (s)')
title('Error comparison for different controllers')
%%
[~, e_rms_1, e_max_1] = get_relevant_error(measurements_reference, 66412+1691, 113555);
1000*[e_rms_1, e_max_1]
%%
[~, e_rms_2, e_max_2] = get_relevant_error(measure_control_stab_yesFF, 32883+845, 80026)
1000*[e_rms_2, e_max_2]
%%
[~, e_rms_3, e_max_3] = get_relevant_error(measure_control_FF_yesFF, 25377+845, 72520)
1000*[e_rms_3, e_max_3]
%% Frequency analysis
error_for_frequency_analysis = get_relevant_error(measure_control_FF_yesFF, 25377+845, 48104);
plot(error_for_frequency_analysis)
%%
pwelch(error_for_frequency_analysis,hann(8000),4000,8000,4000)
%%
[psd, freqs]=pwelch(error_for_frequency_analysis,hann(8000),4000,8000,4000);

semilogx(freqs, db(psd))
xlabel('f (Hz)')
ylabel('Power density (db)')
title('Power spectal density of error for K_{ff} with feedforward')
%% Old version
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
%% Function
function [error_constant_vel_period, e_rms, e_max] = get_relevant_error(measurement,...
    sample_initial, sample_final)
    % measurement has channels: error, acc, vel
    % We unpack them and take only one period
    error = measurement(sample_initial:sample_final,1);
    acc = measurement(sample_initial:sample_final,2);
    velocity = measurement(sample_initial:sample_final,3);
    
    constant_velocity = acc==0 & velocity ~= 0;
    
    error_constant_vel_period = error.*constant_velocity;

    error_for_aggregation = error(constant_velocity);

    e_max = norm(error_for_aggregation,"inf");
    e_rms = rms(error_for_aggregation);
end