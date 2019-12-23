<template>
  <app-user></app-user>
</template>

<script>
  import User from "./components/User"

  export default {
      components: {
          appUser: User
      }
  }
</script>

<style>
  body {
      background-color: #000;
      color: #555;
  }
</style>