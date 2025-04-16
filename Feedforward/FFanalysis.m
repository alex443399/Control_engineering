addpath('Model')
addpath('Measurements')
clear all
clc
%%
load("Feed_forward_measurements_for_report.mat")
%% Load FF (Feed_forward_measurements_for_report.mat)
% We select the correct time samples
error_ff0 = measurements_ff0(45537:117538,1);
error_ff1 = measurements_ff1(45583:117584,1);
error_ff2 = measurements_ff2(45408:117409,1);
error_ff3 = measurements_ff3(110323:182332,1);
%%
figure;
Ts = 1/4000;
plot((1:length(error_ff0))*Ts,error_ff0)
hold on
plot((1:length(error_ff1))*Ts,error_ff1)
hold on
plot((1:length(error_ff2))*Ts,error_ff2)
hold on
plot((1:length(error_ff3))*Ts,error_ff3)
hold off
legend('No FF', 'Added coulomb friction term', 'Added velocity term', 'Added acceleration term')
% [-0.00038 -0.005 -0.00002]
xlabel('Time (s)')
ylabel('error (rad)')
title('Tuning the feedforward')
%%