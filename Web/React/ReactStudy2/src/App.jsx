import React from 'react';
import './App.css';
import Nav from './components/Nav/Nav.jsx'
import {BrowserRouter, Switch, Route} from 'react-router-dom'
import { Redirect } from 'react-router-dom/cjs/react-router-dom.min';
import Page1 from './views/Page1/Page1.jsx'
import Page2 from './views/Page2/Page2.jsx'


class App extends React.Component {
  render() {
    return (
      <BrowserRouter className="app">
        <Nav></Nav>
        <div>
          <Switch>
            <Route path='/page1' component={Page1}></Route>
            <Route path='/page2' component={Page2}></Route>
            <Redirect to='/page1'></Redirect>
          </Switch>
        </div>
      </BrowserRouter>
    )
  }
}

export default App;
