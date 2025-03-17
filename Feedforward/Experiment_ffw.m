%% Pi
p = raspi('10.55.0.1','pi','sperte123')
%% Path
addpath('Model')
addpath('Reference')
%% Measurements
T_measure = 60;
measurements_reference = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error = measurements_reference(:,1);
acc = measurements_reference(:,2);
velocity = measurements_reference(:,3);
%% Checking requirements
% Tv constant = (42842-20959)/4000; So total stroke at constant v=22 is 120.3565
% We chose last period to remove transient effects
% File is measurements_reference_v2.mat
sample_i = 66412;
sample_f = 113555;
error_period = error(sample_i:sample_f);
acc_period = acc(sample_i:sample_f);
velocity_period = velocity(sample_i:sample_f);
constant_velocity_stroke = acc_period==0 & velocity_period ~= 0;
error_constant_velocity = error_period(constant_velocity_stroke);
plot(error_constant_velocity)
max_error = norm(error_constant_velocity, 'Inf')
rms_error = rms(error_constant_velocity)

%% Spectrum during feedforward
error_ffw = measurements_reference(:,1);
pwelch(error_ffw, hann(8000), 4000, 8000, 4000);
%% Feedforward
%% First measurements
T_measure = 60;
measurements_ff0 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff0 = measurements_ff0(:,1);
acc_ff0 = measurements_ff0(:,2);
velocity_ff0 = measurements_ff0(:,3);

%%
plot(error_ff0)
hold on
plot(acc_ff0)
hold off
%%
plot(error_ff0(45537:117538)) % One extra sample, wierd
%% Second measurement
T_measure = 60;
measurements_ff1 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff1 = measurements_ff1(:,1);
acc_ff1 = measurements_ff1(:,2);
velocity_ff1 = measurements_ff1(:,3);
%%
plot(error_ff1)
hold on
plot(acc_ff1)
hold off
%%
plot(error_ff0(45537:117538))
hold on
plot(error_ff1(45583:117584))
hold off
legend('no ff', 'kc')

%% Third measurement
T_measure = 60;
measurements_ff2 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff2 = measurements_ff2(:,1);
acc_ff2 = measurements_ff2(:,2);
velocity_ff2 = measurements_ff2(:,3);
%%
plot(error_ff2)
hold on
plot(acc_ff2)
hold off
%% Fourth measurement
T_measure = 60;
measurements_ff3 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff3 = measurements_ff3(:,1);
acc_ff3 = measurements_ff3(:,2);
velocity_ff3 = measurements_ff3(:,3);
%%
plot(error_ff3)
hold on
plot(acc_ff3)
hold off
%%
plot(error_ff0(45537:117538))
hold on
plot(error_ff1(45583:117584))
hold on
plot(error_ff2(45408:117409))
hold on
plot(error_ff3(110332:182332))
hold off
% [-0.00038 -0.005 -0.00002]