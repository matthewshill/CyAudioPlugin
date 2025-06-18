/*
  ==============================================================================

    CyFxPanel.cpp
    Created: 11 Jun 2025 4:31:34pm
    Author:  Matthew Hill

  ==============================================================================
*/

#include "CyFxPanel.h"
#include "CyParameters.h"
#include "CyHelperFunctions.h"

CyFXPanel::CyFXPanel(CyAudioPluginAudioProcessor* inProcessor) : CyPanelBase(inProcessor)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
    auto* styleParam = cyProcessor->parameters.getRawParameterValue("Type");
    jassert(styleParam != nullptr);
    CyFXPanelStyle currStyle = static_cast<CyFXPanelStyle>(static_cast<int>(*styleParam));
    setFXPanelStyle(currStyle);
};

CyFXPanel::~CyFXPanel() {
    
};

void CyFXPanel::paint(juce::Graphics &g) {
    CyPanelBase::paint(g);
    
    switch(panelStyle) {
        case(CyFXPanelStyle_Delay) : {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        } break;
            
        case(CyFXPanelStyle_Chorus) : {
            g.drawFittedText("CHROUS", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        } break;
        default:
        case(CyFXPanelStyle_TotalNumStyles) : {
            g.drawFittedText("no no no", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
            jassertfalse;
        } break;
    }
    
    for(int i = 0; i < cSliders.size(); ++i) {
        paintComponentLabels(g, cSliders[i]);
    }
}

void CyFXPanel::setFXPanelStyle(CyFXPanelStyle inStyle)
{
    panelStyle = inStyle;
    cSliders.clear();
    
    const int size = 56;
    int x = 130;
    int y = getHeight() * 0.5 - (size*0.5);
    
    switch(panelStyle) {
        case(CyFXPanelStyle_Delay) : {
            CyParameterSlider* time = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_DelayTime]);
            time->setBounds(x, y, size, size);
            addAndMakeVisible(time);
            cSliders.add(time);
            x = x + (size * 2);
            
            CyParameterSlider* feedback = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_DelayFeedback]);
            feedback->setBounds(x, y, size, size);
            x = x + (size*2);
            addAndMakeVisible(feedback);
            cSliders.add(feedback);
            
            CyParameterSlider* wetDry = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_DelayWetDry]);
            wetDry->setBounds(x, y, size, size);
            addAndMakeVisible(wetDry);
            cSliders.add(wetDry);
            
        } break;
            
        case(CyFXPanelStyle_Chorus) : {
            CyParameterSlider* rate = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_ModulationRate]);
            rate->setBounds(x, y, size, size);
            addAndMakeVisible(rate);
            cSliders.add(rate);
            x = x + (size * 2);
            
            CyParameterSlider* depth = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_ModulationDepth]);
            depth->setBounds(x, y, size, size);
            x = x + (size*2);
            addAndMakeVisible(depth);
            cSliders.add(depth);
            
            CyParameterSlider* wetDry = new CyParameterSlider(cyProcessor->parameters, CyParameterID[cParameter_DelayWetDry]);
            wetDry->setBounds(x, y, size, size);
            addAndMakeVisible(wetDry);
            cSliders.add(wetDry);
        } break;
        default:
        case(CyFXPanelStyle_TotalNumStyles) : {
            jassertfalse;
        } break;
    }
    
    repaint();
};

void CyFXPanel::comboBoxChanged(juce::ComboBox* comboBoxThatChanged)
{
    CyFXPanelStyle style = (CyFXPanelStyle)comboBoxThatChanged->getSelectedItemIndex();
    setFXPanelStyle(style);
}
