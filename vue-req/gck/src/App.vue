<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-md-offset-3">
        <br>
        <button @click="selectedComponent = 'appMemory'" class="btn-sm btn btn-primary">appMemory</button>&nbsp;
        <button @click="selectedComponent = 'appNewMemory'" class="btn-sm btn btn-primary">appNewMemory</button>&nbsp;
        <button @click="selectedComponent = 'appAuthor'" class="btn-sm btn btn-primary">appAuthor</button>&nbsp;
        <p>{{ selectedComponent }}</p><hr>

        <!-- Component lerin canlı kalması için yapılan eylem -->
        <keep-alive>
          <component :is="selectedComponent" >
            <h1 slot="heading">Güzel bir gün</h1>
            <p slot="content">Güzel bir anı</p>
          </component>
        </keep-alive>
        <!--
        <appMemory>
          <h1 slot="heading">Güzel bir gün</h1>
          <p slot="content">Güzel bir anı</p>
          <p>slot default</p>
        </appMemory>
        -->
      </div>
    </div>
  </div>
</template>


<script>
  import Memory from "./components/Memory"
  import Author from "./components/Author"
  import NewMemory from "./components/NewMemory"

  export default {
    components: {
      appMemory: Memory,
      appNewMemory: NewMemory,
      appAuthor: Author
    },
    data() {
      return {
        selectedComponent: "appMemory"
      }
    }
  }
</script>






