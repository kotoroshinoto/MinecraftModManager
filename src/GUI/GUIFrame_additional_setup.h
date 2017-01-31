ParentApp* parent_app;
void timer_interval(wxTimerEvent& event);
void process_end(wxProcessEvent& event);

friend struct ClientInstanceTab;
friend struct InstanceTab;
friend struct JarTab;
friend struct ModTab;
friend struct ParentApp;
friend struct ServerInstanceTab;
friend struct SettingsTab;
friend class MineCraftUtils;
friend struct Terminal;



